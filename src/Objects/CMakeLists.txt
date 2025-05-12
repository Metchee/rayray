cmake_minimum_required(VERSION 3.10)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Définir tous les répertoires d'en-têtes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Objects/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/include
)

# Lister tous les fichiers source de l'exécutable principal
set(RAYTRACER_SOURCES
    src/main.cpp
    src/vector.cpp
    src/scene.cpp
    src/SceneConfig.cpp
)

# Lister les fichiers source pour les objets
set(OBJECTS_SOURCES
    src/Objects/sphereObj.cpp
    src/Objects/planeObj.cpp
)

# Créer la bibliothèque statique Objects
add_library(Objects STATIC ${OBJECTS_SOURCES})

# Créer l'exécutable
add_executable(raytracer ${RAYTRACER_SOURCES})

# Lier l'exécutable avec les bibliothèques nécessaires
target_link_libraries(raytracer
    PRIVATE Objects
    PRIVATE config++  # Assurez-vous que libconfig++ est installé
    PRIVATE sfml-system sfml-window sfml-graphics  # Pour SFML si nécessaire
)

# Définir les répertoires d'en-têtes pour l'exécutable
target_include_directories(raytracer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Objects/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/include
)

# Si vous utilisez SFML, assurez-vous que les chemins sont corrects
if(EXISTS "/usr/local/share/SFML/cmake/Modules")
    set(SFML_DIR "/usr/local/share/SFML/cmake/Modules")
endif()