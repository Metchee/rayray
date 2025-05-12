#ifndef RAY_H
#define RAY_H

#include "vector.hpp"

class Ray {
    public:
        Ray() {}
        Ray(const point3& origin, const Vector3& direction) : orig(origin), dir(direction) {}   
        const point3& origin() const  { return orig; }
        const Vector3& direction() const { return dir; }    
        point3 at(double t) const {
          return orig + (dir * t);
        }
    private:
        point3 orig;
        Vector3 dir;
};

#endif
