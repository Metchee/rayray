# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Les répertoires d'inclusion
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src/Objects/include
    ${CMAKE_SOURCE_DIR}/src/Materials/include
    ${CMAKE_SOURCE_DIR}/include/lights
)

# Ajout des sous-répertoires
add_subdirectory(src/Objects)

# Les fichiers source principaux
set(SOURCES
    src/main.cpp
    src/vector.cpp
    src/scene.cpp
)

# Création de l'exécutable
add_executable(raytracer ${SOURCES})

# Lien avec les sous-bibliothèques
target_link_libraries(raytracer PRIVATE Objects)

# Trouver et lier les bibliothèques externes
find_library(LIBCONFIG_LIBRARY NAMES config++ libconfig++)
if(NOT LIBCONFIG_LIBRARY)
    message(FATAL_ERROR "libconfig++ library not found")
endif()

find_library(SFML_GRAPHICS_LIBRARY NAMES sfml-graphics)
find_library(SFML_WINDOW_LIBRARY NAMES sfml-window)
find_library(SFML_SYSTEM_LIBRARY NAMES sfml-system)

# Liaison avec les bibliothèques externes
target_link_libraries(raytracer PRIVATE 
    ${LIBCONFIG_LIBRARY}
    ${SFML_GRAPHICS_LIBRARY}
    ${SFML_WINDOW_LIBRARY}
    ${SFML_SYSTEM_LIBRARY}
)

# Installation de l'exécutable
install(TARGETS raytracer DESTINATION bin)

# Création du répertoire plugins
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)