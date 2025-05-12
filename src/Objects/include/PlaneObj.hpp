// src/Objects/include/PlaneObj.hpp
#pragma once
#include <iostream>
#include "IMaterial.hpp"
#include "vector.hpp"
#include "IObject.hpp"
#include <libconfig.h++>

class Plane : public IObject {
public:
    Plane(IMaterial &material, std::string &axis, const Vector3 &position, const Vector3 &color);
    IMaterial &getMaterial() override { return material; }
    
    const std::string& getAxis() const { return axis; }
    const Vector3& getPosition() const { return position; }
    const Vector3& getColor() const { return color; }

private:
    IMaterial &material;
    std::string axis;
    Vector3 position;
    Vector3 color;
};