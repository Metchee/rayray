// include/Scene.hpp
#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "IObject.hpp"
#include "SceneConfig.hpp"

class Scene {
public:
    Scene(const std::string& configFile);
    void render();

private:
    void setupCamera();
    void createObjects();
    void setupLights();

    SceneConfig config;
    std::vector<std::unique_ptr<IObject>> objects;
    std::vector<std::unique_ptr<IMaterial>> materials; // Pour stocker les matériaux
};