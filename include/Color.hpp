#pragma once
#include "vector.hpp"
#include "Ray.hpp"
#include <iostream>
using color = Vector3;

void write_color(std::ostream& out, const color &pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}


color ray_color(const Ray& r) {
    Vector3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}
