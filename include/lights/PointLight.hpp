// include/lights/PointLight.hpp

#pragma once
#include "ILight.hpp"

class PointLight : public ILight {
public:
    PointLight(const Vector3& position, double intensity)
        : position_(position), intensity_(intensity) {}
    
    Vector3 getDirection(const Vector3& point) const override {
        return unit_vector(position_ - point);
    }
    
    double getIntensity(const Vector3& point) const override {
        double distance = (position_ - point).length();
        return intensity_ / (1.0 + 0.01 * distance * distance); // Attenuation formula
    }
    
    bool isDirectional() const override {
        return false;
    }
    
private:
    Vector3 position_;
    double intensity_;
};