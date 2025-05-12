// src/main.cpp
#include "Scene.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "USAGE: " << argv[0] << " <SCENE_FILE>" << std::endl;
        std::cerr << "SCENE_FILE: scene configuration" << std::endl;
        return 84;
    }
    
    try {
        Scene scene(argv[1]);
        scene.render();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}