// src/Materials/include/BasicMaterial.hpp
#pragma once
#include "IMaterial.hpp"
#include "vector.hpp"

class Basic : public IMaterial {
public:
    Basic(const Vector3 &color, const Vector3 &diffuse, double shine)
        : color_(color), diffuse_(diffuse), shine_(shine) {}
    
    const Vector3& getColor() const { return color_; }
    const Vector3& getDiffuse() const { return diffuse_; }
    double getShine() const { return shine_; }
    
private:
    Vector3 color_;
    Vector3 diffuse_;
    double shine_;
};