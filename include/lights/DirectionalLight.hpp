// include/lights/DirectionalLight.hpp

#pragma once
#include "ILight.hpp"

class DirectionalLight : public ILight {
public:
    DirectionalLight(const Vector3& direction, double intensity)
        : direction_(unit_vector(direction)), intensity_(intensity) {}
    
    Vector3 getDirection(const Vector3& point) const override {
        return direction_; // Same direction regardless of point
    }
    
    double getIntensity(const Vector3& point) const override {
        return intensity_; // Constant intensity
    }
    
    bool isDirectional() const override {
        return true;
    }
    
private:
    Vector3 direction_;
    double intensity_;
};