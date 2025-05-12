// src/scene.cpp
#include "Scene.hpp"
#include "Objects/include/SphereObj.hpp"
#include "Objects/include/PlaneObj.hpp"
#include "Materials/include/BasicMaterial.hpp"
#include <iostream>

Scene::Scene(const std::string& configFile) : config(configFile) {
    setupCamera();
    createObjects();
    setupLights();
}

void Scene::setupCamera() {
    SceneConfig::CameraConfig camera = config.getCamera();
    // Configuration de la caméra pour le rendu
    std::cout << "Camera set up with resolution: " << camera.width << "x" << camera.height << std::endl;
    std::cout << "Camera position: " << camera.position << std::endl;
    std::cout << "Camera rotation: " << camera.rotation << std::endl;
    std::cout << "Camera field of view: " << camera.fieldOfView << " degrees" << std::endl;
}

void Scene::createObjects() {
    // Créer les objets sphère
    auto spheres = config.getSpheres();
    for (const auto& sphereConfig : spheres) {
        // Créer un matériau de base pour la sphère
        auto material = std::make_unique<Basic>(
            sphereConfig.color,
            Vector3(0.7, 0.7, 0.7), // Diffuse par défaut
            10.0  // Brillance par défaut
        );
        
        // Ajouter le matériau à la liste
        materials.push_back(std::move(material));
        
        // Créer la sphère avec le matériau
        auto sphere = std::make_unique<Sphere>(
            *materials.back(),
            sphereConfig.center,
            sphereConfig.color,
            sphereConfig.radius
        );
        
        // Ajouter la sphère à la liste des objets
        objects.push_back(std::move(sphere));
        std::cout << "Added sphere at " << sphereConfig.center << " with radius " << sphereConfig.radius << std::endl;
    }
    
    // Créer les objets plan
    auto planes = config.getPlanes();
    for (const auto& planeConfig : planes) {
        // Créer un matériau de base pour le plan
        auto material = std::make_unique<Basic>(
            planeConfig.color,
            Vector3(0.7, 0.7, 0.7), // Diffuse par défaut
            10.0  // Brillance par défaut
        );
        
        // Ajouter le matériau à la liste
        materials.push_back(std::move(material));
        
        // Créer la position en vecteur selon l'axe
        Vector3 position(0, 0, 0);
        if (planeConfig.axis == "X") {
            position = Vector3(planeConfig.position, 0, 0);
        } else if (planeConfig.axis == "Y") {
            position = Vector3(0, planeConfig.position, 0);
        } else if (planeConfig.axis == "Z") {
            position = Vector3(0, 0, planeConfig.position);
        }
        
        std::string axis = planeConfig.axis;
        auto plane = std::make_unique<Plane>(
            *materials.back(),
            axis,
            position,
            planeConfig.color
        );
        
        // Ajouter le plan à la liste des objets
        objects.push_back(std::move(plane));
        std::cout << "Added plane with axis " << planeConfig.axis << " at position " << planeConfig.position << std::endl;
    }
}

void Scene::setupLights() {
    SceneConfig::LightConfig lights = config.getLights();
    
    std::cout << "Ambient light multiplier: " << lights.ambient << std::endl;
    std::cout << "Diffuse light multiplier: " << lights.diffuse << std::endl;
    
    std::cout << "Point lights: " << std::endl;
    for (const auto& pointLight : lights.pointLights) {
        std::cout << "- " << pointLight << std::endl;
    }
    
    std::cout << "Directional lights: " << std::endl;
    for (const auto& directionalLight : lights.directionalLights) {
        std::cout << "- " << directionalLight << std::endl;
    }
}

void Scene::render() {
    // Implémentation du rendu de la scène
    std::cout << "Rendering scene with " << objects.size() << " objects..." << std::endl;
    // TODO: Implémentez la logique de rendu ici
}