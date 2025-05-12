// include/SceneConfig.hpp
#pragma once

#include <libconfig.h++>
#include <string>
#include <vector>
#include <memory>
#include "vector.hpp"

class SceneConfig {
public:
    struct CameraConfig {
        int width;
        int height;
        Vector3 position;
        Vector3 rotation;
        double fieldOfView;
    };

    struct SphereConfig {
        Vector3 center;
        double radius;
        Vector3 color;
    };

    struct PlaneConfig {
        std::string axis;
        double position;
        Vector3 color;
    };

    struct LightConfig {
        double ambient;
        double diffuse;
        std::vector<Vector3> pointLights;
        std::vector<Vector3> directionalLights;
    };

    SceneConfig(const std::string& filename);
    ~SceneConfig() = default;

    CameraConfig getCamera() const { return camera; }
    std::vector<SphereConfig> getSpheres() const { return spheres; }
    std::vector<PlaneConfig> getPlanes() const { return planes; }
    LightConfig getLights() const { return lights; }

private:
    void parseCamera(const libconfig::Config& cfg);
    void parsePrimitives(const libconfig::Config& cfg);
    void parseLights(const libconfig::Config& cfg);
    Vector3 parseVector3(const libconfig::Setting& setting);
    Vector3 parseColor(const libconfig::Setting& setting);

    CameraConfig camera;
    std::vector<SphereConfig> spheres;
    std::vector<PlaneConfig> planes;
    LightConfig lights;
};