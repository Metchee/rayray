// src/SceneConfig.cpp
#include "SceneConfig.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

SceneConfig::SceneConfig(const std::string& filename) {
    std::cout << "Loading config file: " << filename << std::endl;
    
    libconfig::Config cfg;
    
    try {
        cfg.readFile(filename.c_str());
        std::cout << "Config file loaded successfully" << std::endl;
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file: " << filename << std::endl;
        throw std::runtime_error("File I/O error");
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        throw std::runtime_error("Parse error");
    }

    parseCamera(cfg);
    parsePrimitives(cfg);
    parseLights(cfg);
}

void SceneConfig::parseCamera(const libconfig::Config& cfg) {
    // Initialize camera with default values
    camera.width = 800;
    camera.height = 600;
    camera.position = Vector3(0, 0, 0);
    camera.rotation = Vector3(0, 0, 0);
    camera.fieldOfView = 72.0;
    
    try {
        if (cfg.exists("camera")) {
            const libconfig::Setting& cameraSetting = cfg.lookup("camera");
            
            // Resolution
            if (cameraSetting.exists("resolution")) {
                const libconfig::Setting& resolution = cameraSetting["resolution"];
                int width, height;
                if (resolution.lookupValue("width", width)) {
                    camera.width = width;
                }
                if (resolution.lookupValue("height", height)) {
                    camera.height = height;
                }
            }
            
            // Position
            if (cameraSetting.exists("position")) {
                const libconfig::Setting& position = cameraSetting["position"];
                double x = 0, y = 0, z = 0;
                position.lookupValue("x", x);
                position.lookupValue("y", y);
                position.lookupValue("z", z);
                camera.position = Vector3(x, y, z);
            }
            
            // Rotation
            if (cameraSetting.exists("rotation")) {
                const libconfig::Setting& rotation = cameraSetting["rotation"];
                double x = 0, y = 0, z = 0;
                rotation.lookupValue("x", x);
                rotation.lookupValue("y", y);
                rotation.lookupValue("z", z);
                camera.rotation = Vector3(x, y, z);
            }
            
            // Field of view
            double fov;
            if (cameraSetting.lookupValue("fieldOfView", fov)) {
                camera.fieldOfView = fov;
            }
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error in parseCamera: " << ex.what() << std::endl;
    }
    
    std::cout << "Camera parsed: resolution=" << camera.width << "x" << camera.height
              << ", position=" << camera.position
              << ", rotation=" << camera.rotation
              << ", fov=" << camera.fieldOfView << std::endl;
}

void SceneConfig::parsePrimitives(const libconfig::Config& cfg) {
    try {
        if (cfg.exists("primitives")) {
            const libconfig::Setting& primitivesSetting = cfg.lookup("primitives");
            
            // Spheres
            if (primitivesSetting.exists("spheres")) {
                const libconfig::Setting& spheresList = primitivesSetting["spheres"];
                int sphereCount = spheresList.getLength();
                std::cout << "Found " << sphereCount << " spheres in config" << std::endl;
                
                for (int i = 0; i < sphereCount; ++i) {
                    try {
                        const libconfig::Setting& sphereItem = spheresList[i];
                        
                        // Default values
                        double x = 0, y = 0, z = 0, r = 0;
                        
                        // Read position
                        sphereItem.lookupValue("x", x);
                        sphereItem.lookupValue("y", y);
                        sphereItem.lookupValue("z", z);
                        sphereItem.lookupValue("r", r);
                        
                        // Read color
                        int red = 255, green = 0, blue = 0; // Default to red
                        if (sphereItem.exists("color")) {
                            const libconfig::Setting& colorSetting = sphereItem["color"];
                            colorSetting.lookupValue("r", red);
                            colorSetting.lookupValue("g", green);
                            colorSetting.lookupValue("b", blue);
                        }
                        
                        SphereConfig sphere;
                        sphere.center = Vector3(x, y, z);
                        sphere.radius = r;
                        sphere.color = Vector3(red / 255.0, green / 255.0, blue / 255.0);
                        
                        std::cout << "Sphere " << i << ": center=" << sphere.center
                                  << ", radius=" << sphere.radius
                                  << ", color=" << sphere.color << std::endl;
                        
                        spheres.push_back(sphere);
                    } catch (const std::exception& ex) {
                        std::cerr << "Error parsing sphere " << i << ": " << ex.what() << std::endl;
                    }
                }
            }
            
            // Planes
            if (primitivesSetting.exists("planes")) {
                const libconfig::Setting& planesList = primitivesSetting["planes"];
                int planeCount = planesList.getLength();
                std::cout << "Found " << planeCount << " planes in config" << std::endl;
                
                for (int i = 0; i < planeCount; ++i) {
                    try {
                        const libconfig::Setting& planeItem = planesList[i];
                        
                        // Default values
                        std::string axis = "Z";
                        double position = 0;
                        
                        // Read axis and position
                        planeItem.lookupValue("axis", axis);
                        planeItem.lookupValue("position", position);
                        
                        // Read color
                        int red = 0, green = 0, blue = 255; // Default to blue
                        if (planeItem.exists("color")) {
                            const libconfig::Setting& colorSetting = planeItem["color"];
                            colorSetting.lookupValue("r", red);
                            colorSetting.lookupValue("g", green);
                            colorSetting.lookupValue("b", blue);
                        }
                        
                        PlaneConfig plane;
                        plane.axis = axis;
                        plane.position = position;
                        plane.color = Vector3(red / 255.0, green / 255.0, blue / 255.0);
                        
                        std::cout << "Plane " << i << ": axis=" << plane.axis
                                  << ", position=" << plane.position
                                  << ", color=" << plane.color << std::endl;
                        
                        planes.push_back(plane);
                    } catch (const std::exception& ex) {
                        std::cerr << "Error parsing plane " << i << ": " << ex.what() << std::endl;
                    }
                }
            }
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error in parsePrimitives: " << ex.what() << std::endl;
    }
}

void SceneConfig::parseLights(const libconfig::Config& cfg) {
    // Initialize lights with default values
    lights.ambient = 0.2;
    lights.diffuse = 0.8;
    
    try {
        if (cfg.exists("lights")) {
            const libconfig::Setting& lightsSetting = cfg.lookup("lights");
            
            // Read ambient and diffuse
            double ambient, diffuse;
            if (lightsSetting.lookupValue("ambient", ambient)) {
                lights.ambient = ambient;
            }
            if (lightsSetting.lookupValue("diffuse", diffuse)) {
                lights.diffuse = diffuse;
            }
            
            // Point lights
            if (lightsSetting.exists("point")) {
                const libconfig::Setting& pointsList = lightsSetting["point"];
                int pointCount = pointsList.getLength();
                std::cout << "Found " << pointCount << " point lights in config" << std::endl;
                
                for (int i = 0; i < pointCount; ++i) {
                    try {
                        const libconfig::Setting& pointItem = pointsList[i];
                        
                        // Default values
                        double x = 0, y = 0, z = 0;
                        
                        // Read position
                        pointItem.lookupValue("x", x);
                        pointItem.lookupValue("y", y);
                        pointItem.lookupValue("z", z);
                        
                        Vector3 pointLight(x, y, z);
                        std::cout << "Point light " << i << ": " << pointLight << std::endl;
                        lights.pointLights.push_back(pointLight);
                    } catch (const std::exception& ex) {
                        std::cerr << "Error parsing point light " << i << ": " << ex.what() << std::endl;
                    }
                }
            }
            
            // Directional lights
            if (lightsSetting.exists("directional")) {
                const libconfig::Setting& directionalsList = lightsSetting["directional"];
                int directionalCount = directionalsList.getLength();
                std::cout << "Found " << directionalCount << " directional lights in config" << std::endl;
                
                for (int i = 0; i < directionalCount; ++i) {
                    try {
                        const libconfig::Setting& directionalItem = directionalsList[i];
                        
                        // Default values
                        double x = 0, y = 0, z = 0;
                        
                        // Read direction
                        directionalItem.lookupValue("x", x);
                        directionalItem.lookupValue("y", y);
                        directionalItem.lookupValue("z", z);
                        
                        Vector3 directionalLight(x, y, z);
                        std::cout << "Directional light " << i << ": " << directionalLight << std::endl;
                        lights.directionalLights.push_back(directionalLight);
                    } catch (const std::exception& ex) {
                        std::cerr << "Error parsing directional light " << i << ": " << ex.what() << std::endl;
                    }
                }
            }
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error in parseLights: " << ex.what() << std::endl;
    }
    
    std::cout << "Lights parsed: ambient=" << lights.ambient << ", diffuse=" << lights.diffuse
              << ", point=" << lights.pointLights.size()
              << ", directional=" << lights.directionalLights.size() << std::endl;
}

Vector3 SceneConfig::parseVector3(const libconfig::Setting& setting) {
    double x = 0, y = 0, z = 0;
    
    try {
        setting.lookupValue("x", x);
        setting.lookupValue("y", y);
        setting.lookupValue("z", z);
    } catch (const std::exception& ex) {
        std::cerr << "Error in parseVector3: " << ex.what() << std::endl;
    }
    
    return Vector3(x, y, z);
}

Vector3 SceneConfig::parseColor(const libconfig::Setting& setting) {
    int r = 0, g = 0, b = 0;
    
    try {
        setting.lookupValue("r", r);
        setting.lookupValue("g", g);
        setting.lookupValue("b", b);
    } catch (const std::exception& ex) {
        std::cerr << "Error in parseColor: " << ex.what() << std::endl;
    }
    
    return Vector3(r / 255.0, g / 255.0, b / 255.0);
}