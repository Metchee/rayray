include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../Materials/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

set(OBJECTS_SOURCES
    sphereObj.cpp
    planeObj.cpp
)

add_library(Objects STATIC ${OBJECTS_SOURCES})

target_include_directories(Objects PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../Materials/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)
