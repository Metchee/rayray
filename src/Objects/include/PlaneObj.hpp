#pragma once
#include <iostream>
#include "IMaterial.hpp"
#include "vector.hpp"
#include "IObject.hpp"
#include <libconfig.h++>

class Plane : public IObject {
    public:
        Plane(IMaterial &_material, std::string &_axis, const Vector3 &_position, Vector3 &_color);
        IMaterial &getMaterial() override {return material;}
    private:
        IMaterial &material;
        std::string axis;
        Vector3 position;
        Vector3 color;
};