#include "Color.hpp"
#include "Ray.hpp"
#include "vector.hpp"
#include "../include/Scene.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        // Create the scene from command-line arguments
        Scene scene(argc, argv);
        
        // Print debug info to verify parsing
        scene.printDebugInfo();
        
        // Future: Render the scene to a file
        // scene.render("output.ppm");
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84; // As per project requirements for error code
    }
}