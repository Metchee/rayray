// src/Objects/planeObj.cpp
#include "PlaneObj.hpp"
#include "IMaterial.hpp"
#include "vector.hpp"

Plane::Plane(IMaterial &material, std::string &axis, const Vector3 &position, const Vector3 &color)
    : material(material), axis(axis), position(position), color(color)
{
}