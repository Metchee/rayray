#include "../include/Scene.hpp"
#include "Objects/include/SphereObj.hpp"
#include "Objects/include/PlaneObj.hpp"
#include "Materials/include/BasicMaterial.hpp"
#include <memory>
#include <stdexcept>
#include <libconfig.h++>

Scene::Scene(int ac, const char *av[]) {
    if (ac < 2) {
        throw std::runtime_error("Error: No scene file provided");
    }

    const char* filename = av[1];
    libconfig::Config cfg;

    try {
        cfg.readFile(filename);
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "Error: Cannot read file " << filename << std::endl;
        throw std::runtime_error("File IO error");
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        throw std::runtime_error("Parse error");
    }

    // Parse each section of the config file
    try {
        const libconfig::Setting& cameraSettings = cfg.lookup("camera");
        parseCamera(cameraSettings);
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Warning: Camera settings not found, using defaults" << std::endl;
    }

    try {
        const libconfig::Setting& primitivesSettings = cfg.lookup("primitives");
        parsePrimitives(primitivesSettings);
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Warning: No primitives defined in the scene" << std::endl;
    }

    try {
        const libconfig::Setting& lightsSettings = cfg.lookup("lights");
        parseLights(lightsSettings);
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Warning: Lights settings not found, using defaults" << std::endl;
    }
}