#include "IObject.hpp"
#include "include/SphereObj.hpp"

Sphere::Sphere(IMaterial &material, const Vector3 &center, const Vector3 &color, double radius)
    : material(material), center(center), color(color), radius(radius)
{
}