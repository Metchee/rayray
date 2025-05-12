cmake_minimum_required(VERSION 3.10)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/Objects)

add_executable(raytracer
    src/main.cpp
    src/vector.cpp
)

target_include_directories(raytracer PRIVATE include)
target_link_libraries(raytracer PRIVATE Objects)

set(SFML_DIR "/usr/local/share/SFML/cmake/Modules")