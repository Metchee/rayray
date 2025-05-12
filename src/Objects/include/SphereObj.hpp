#pragma once
#include <iostream>
#include "IMaterial.hpp"
#include "vector.hpp"
#include "IObject.hpp"
#include <libconfig.h++>

class Sphere : public IObject {
    public:
        Sphere(IMaterial &material, const Vector3 &center, const Vector3 &color, double radius);
        IMaterial &getMaterial() override {return material;}
    private:
        IMaterial &material;
        Vector3 center;
        Vector3 color;
        double radius;
};