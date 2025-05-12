// include/ILight.hpp

#pragma once
#include "vector.hpp"

class ILight {
public:
    virtual ~ILight() = default;
    virtual Vector3 getDirection(const Vector3& point) const = 0;
    virtual double getIntensity(const Vector3& point) const = 0;
    virtual bool isDirectional() const = 0;
};