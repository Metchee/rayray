#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "IObject.hpp"
#include "vector.hpp"
#include "Ray.hpp"
#include <libconfig.h++>

// Forward declarations
class IMaterial;

// Light structure
struct PointLight {
    Vector3 position;
    Vector3 color{1.0, 1.0, 1.0}; // Default white light
};

struct DirectionalLight {
    Vector3 direction;
    Vector3 color{1.0, 1.0, 1.0}; // Default white light
};

class Scene {
public:
    // Constructor takes command line arguments
    Scene(int ac, const char *av[]);
    
    // Add an object to the scene
    void addObject(std::unique_ptr<IObject> obj);
    
    // Factory method to create different types of objects
    std::unique_ptr<IObject> createObject(const std::string &type);
    
    // Render the scene to a PPM file
    void render(const std::string &outputFile = "output.ppm") const;
    
    // Ray casting and intersection testing
    color castRay(const Ray &ray, int depth = 0) const;
    
    // Getters for scene parameters
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    Vector3 getCameraPosition() const { return cameraPosition_; }
    Vector3 getCameraRotation() const { return cameraRotation_; }
    double getFieldOfView() const { return fieldOfView_; }
    
private:
    // Camera settings
    int width_ = 800;
    int height_ = 600;
    Vector3 cameraPosition_{0, 0, 0};
    Vector3 cameraRotation_{0, 0, 0};
    double fieldOfView_ = 72.0;
    
    // Lighting parameters
    double ambientIntensity_ = 0.2;
    double diffuseIntensity_ = 0.8;
    std::vector<PointLight> pointLights_;
    std::vector<DirectionalLight> directionalLights_;
    
    // Objects in the scene
    std::vector<std::unique_ptr<IObject>> objects_;
    
    // Helper methods for configuration parsing
    void parseCamera(const libconfig::Setting &camera);
    void parsePrimitives(const libconfig::Setting &primitives);
    void parseLights(const libconfig::Setting &lights);
    
    // Material cache to avoid duplicating materials
    std::vector<std::shared_ptr<IMaterial>> materials_;
};