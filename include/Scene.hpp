// include/Scene.hpp

#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "IObject.hpp"
#include "ILight.hpp"
#include "Camera.hpp"
#include <libconfig.h++>

class Scene {
public:
    Scene(int ac, const char *av[]);
    void addObject(std::unique_ptr<IObject> obj);
    std::unique_ptr<IObject> createObject(const std::string &type);
    
    const std::vector<std::unique_ptr<IObject>>& getObjects() const;
    const std::vector<std::unique_ptr<ILight>>& getLights() const;
    const Camera& getCamera() const;
    
private:
    void parseCamera(const libconfig::Config &cfg);
    void parsePrimitives(const libconfig::Config &cfg);
    void parseLights(const libconfig::Config &cfg);
    
    std::unique_ptr<Camera> camera_;
    std::vector<std::unique_ptr<IObject>> objects_;
    std::vector<std::unique_ptr<ILight>> lights_;
    std::vector<std::shared_ptr<IMaterial>> materials_;
};