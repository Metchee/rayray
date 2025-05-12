// src/scene.cpp
#include "Scene.hpp"
#include "Objects/include/SphereObj.hpp"
#include "Objects/include/PlaneObj.hpp"
#include "lights/AmbientLight.hpp"
#include "lights/PointLight.hpp"
#include "lights/DirectionalLight.hpp"
#include "Materials/include/BasicMaterial.hpp"
#include <iostream>
#include <memory>
#include <libconfig.h++>

using namespace libconfig;

Scene::Scene(int ac, const char *av[])
{
    if (ac < 2) {
        std::cerr << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        exit(84);
    }
    
    Config cfg;
    try {
        // Read the file
        cfg.readFile(av[1]);
    } catch(const FileIOException &fioex) {
        std::cerr << "Error: Cannot read file " << av[1] << std::endl;
        exit(84);
    } catch(const ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        exit(84);
    }

    try {
        // Parse camera settings
        parseCamera(cfg);
        
        // Parse primitives
        parsePrimitives(cfg);
        
        // Parse lights
        parseLights(cfg);
        
    } catch(const SettingNotFoundException &nfex) {
        std::cerr << "Setting not found: " << nfex.getPath() << std::endl;
        exit(84);
    } catch(const SettingTypeException &stex) {
        std::cerr << "Setting type error: " << stex.getPath() << std::endl;
        exit(84);
    } catch(const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        exit(84);
    }
}

void Scene::parseCamera(const Config &cfg)
{
    const Setting &cameraSettings = cfg.lookup("camera");
    
    // Get resolution
    const Setting &resolutionSetting = cameraSettings["resolution"];
    int width = resolutionSetting["width"];
    int height = resolutionSetting["height"];
    
    // Get position
    const Setting &positionSetting = cameraSettings["position"];
    double posX = positionSetting["x"];
    double posY = positionSetting["y"];
    double posZ = positionSetting["z"];
    Vector3 position(posX, posY, posZ);
    
    // Get rotation
    const Setting &rotationSetting = cameraSettings["rotation"];
    double rotX = rotationSetting["x"];
    double rotY = rotationSetting["y"];
    double rotZ = rotationSetting["z"];
    Vector3 rotation(rotX, rotY, rotZ);
    
    // Get field of view
    double fov = cameraSettings["fieldOfView"];
    
    // Create camera object and store it
    camera_ = std::make_unique<Camera>(width, height, position, rotation, fov);
}

void Scene::parsePrimitives(const Config &cfg)
{
    const Setting &primitivesSettings = cfg.lookup("primitives");
    
    // Parse spheres
    if (primitivesSettings.exists("spheres")) {
        const Setting &spheres = primitivesSettings["spheres"];
        int sphereCount = spheres.getLength();
        
        for (int i = 0; i < sphereCount; ++i) {
            const Setting &sphere = spheres[i];
            
            // Get sphere parameters
            double x = sphere["x"];
            double y = sphere["y"];
            double z = sphere["z"];
            double radius = sphere["r"];
            Vector3 center(x, y, z);
            
            // Get color
            const Setting &colorSetting = sphere["color"];
            int r = colorSetting["r"];
            int g = colorSetting["g"];
            int b = colorSetting["b"];
            Vector3 color(r/255.0, g/255.0, b/255.0);
            
            // Create a basic material for the sphere
            auto material = std::make_shared<Basic>(color, Vector3(0.8, 0.8, 0.8), 10.0);
            materials_.push_back(material);
            
            // Create and add the sphere
            auto sphereObj = std::make_unique<Sphere>(*material, center, color, radius);
            objects_.push_back(std::move(sphereObj));
        }
    }
    
    // Parse planes
    if (primitivesSettings.exists("planes")) {
        const Setting &planes = primitivesSettings["planes"];
        int planeCount = planes.getLength();
        
        for (int i = 0; i < planeCount; ++i) {
            const Setting &plane = planes[i];
            
            // Get plane parameters
            std::string axis = plane["axis"].c_str();
            double position = plane["position"];
            
            // Get color
            const Setting &colorSetting = plane["color"];
            int r = colorSetting["r"];
            int g = colorSetting["g"];
            int b = colorSetting["b"];
            Vector3 color(r/255.0, g/255.0, b/255.0);
            Vector3 posVec;
            
            if (axis == "X")
                posVec = Vector3(position, 0, 0);
            else if (axis == "Y")
                posVec = Vector3(0, position, 0);
            else // Z
                posVec = Vector3(0, 0, position);
                
            // Create a basic material for the plane
            auto material = std::make_shared<Basic>(color, Vector3(0.8, 0.8, 0.8), 10.0);
            materials_.push_back(material);
            
            // Create and add the plane
            auto planeObj = std::make_unique<Plane>(*material, axis, posVec, color);
            objects_.push_back(std::move(planeObj));
        }
    }
}

void Scene::parseLights(const Config &cfg)
{
    const Setting &lightsSettings = cfg.lookup("lights");
    
    // Get ambient and diffuse light settings
    double ambient = lightsSettings["ambient"];
    double diffuse = lightsSettings["diffuse"];
    
    // Create an ambient light
    auto ambientLight = std::make_unique<AmbientLight>(ambient);
    lights_.push_back(std::move(ambientLight));
    
    // Parse point lights
    if (lightsSettings.exists("point")) {
        const Setting &pointLights = lightsSettings["point"];
        int pointLightCount = pointLights.getLength();
        
        for (int i = 0; i < pointLightCount; ++i) {
            const Setting &light = pointLights[i];
            
            // Get light position
            double x = light["x"];
            double y = light["y"];
            double z = light["z"];
            Vector3 position(x, y, z);
            
            // Create and add the point light
            auto pointLight = std::make_unique<PointLight>(position, diffuse);
            lights_.push_back(std::move(pointLight));
        }
    }
    
    // Parse directional lights
    if (lightsSettings.exists("directional")) {
        const Setting &directionalLights = lightsSettings["directional"];
        int directionalLightCount = directionalLights.getLength();
        
        for (int i = 0; i < directionalLightCount; ++i) {
            const Setting &light = directionalLights[i];
            
            // Get light direction (assuming it's stored as x, y, z)
            double x = light["x"];
            double y = light["y"];
            double z = light["z"];
            Vector3 direction(x, y, z);
            
            // Create and add the directional light
            auto dirLight = std::make_unique<DirectionalLight>(direction, diffuse);
            lights_.push_back(std::move(dirLight));
        }
    }
}

void Scene::addObject(std::unique_ptr<IObject> obj)
{
    objects_.push_back(std::move(obj));
}

std::unique_ptr<IObject> Scene::createObject(const std::string &type)
{
    // This would be better with a Factory pattern
    if (type == "Sphere") {
        auto material = std::make_shared<Basic>(Vector3(1, 0, 0), Vector3(0.8, 0.8, 0.8), 10.0);
        materials_.push_back(material);
        return std::make_unique<Sphere>(*material, Vector3(0, 0, 0), Vector3(1, 0, 0), 1.0);
    } else if (type == "Plane") {
        auto material = std::make_shared<Basic>(Vector3(0, 1, 0), Vector3(0.8, 0.8, 0.8), 10.0);
        materials_.push_back(material);
        std::string axis = "Z";
        return std::make_unique<Plane>(*material, axis, Vector3(0, 0, 0), Vector3(0, 1, 0));
    }
    return nullptr;
}

const std::vector<std::unique_ptr<IObject>>& Scene::getObjects() const
{
    return objects_;
}

const std::vector<std::unique_ptr<ILight>>& Scene::getLights() const
{
    return lights_;
}

const Camera& Scene::getCamera() const
{
    return *camera_;
}