#include "PlaneObj.hpp"
#include "IMaterial.hpp"
#include "vector.hpp"

Plane::Plane(IMaterial &_material, std::string &_axis, const Vector3 &_position, Vector3 &_color)
    : material(_material), axis(_axis), position(_position), color(_color)
{
}
