// include/lights/AmbientLight.hpp

#pragma once
#include "ILight.hpp"

class AmbientLight : public ILight {
public:
    AmbientLight(double intensity) : intensity_(intensity) {}
    
    Vector3 getDirection(const Vector3& point) const override {
        return Vector3(0, 0, 0); // Direction doesn't matter for ambient light
    }
    
    double getIntensity(const Vector3& point) const override {
        return intensity_;
    }
    
    bool isDirectional() const override {
        return false;
    }
    
private:
    double intensity_;
};