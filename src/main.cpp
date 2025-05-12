// src/main.cpp
#include "Scene.hpp"
#include "Color.hpp"
#include "Ray.hpp"
#include "vector.hpp"
#include <iostream>
#include <fstream>

int main(int argc, const char *argv[]) {
    try {
        // Parse the scene file and create the scene
        Scene scene(argc, argv);
        
        // Get camera settings
        const Camera& camera = scene.getCamera();
        int image_width = camera.getWidth();
        int image_height = camera.getHeight();
        
        // PPM header
        std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
        
        // Render the scene
        for (int j = 0; j < image_height; j++) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; i++) {
                // Get the ray for this pixel
                Ray ray = camera.getRay(i, j);
                
                // In a complete implementation, you would find intersections with objects
                // and calculate the color based on materials and lighting
                // For now, use the simple sky gradient
                color pixel_color = ray_color(ray);
                write_color(std::cout, pixel_color);
            }
        }
        
        std::clog << "\rDone.                 \n";
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}