#include "vector.hpp"
#include <cmath>

Vector3::Vector3()
{
    _x = 0;
    _y = 0;
    _z = 0;
}

Vector3::Vector3(double x, double y, double z) : _x(x), _y(y), _z(z) {}

Vector3::~Vector3() {}

double Vector3::length() const
{
    return sqrt(pow(x(), 2) + pow(y(), 2) + pow(z(), 2));
}

double Vector3::dot(const Vector3 &other) const
{
    return x() * other.x() + y() * other.y() + z() * other.z();
}

Vector3 Vector3::operator=(const Vector3 &other)
{
    if (this != &other) {
        _x = other.x();
        _y = other.y();
        _z = other.z();
    }
    return *this;
}

Vector3 Vector3::operator+(const Vector3 &other) const
{
    return Vector3(x() + other.x(), y() + other.y(), z() + other.z());
}

Vector3 Vector3::operator-(const Vector3 &other) const
{
    return Vector3(x() - other.x(), y() - other.y(), z() - other.z());
}

Vector3 Vector3::operator*(const Vector3 &other) const
{
    return Vector3(x() * other.x(), y() * other.y(), z() * other.z());
}

Vector3 Vector3::operator/(const Vector3 &other) const
{
    if (other.x() != 0 && other.y() != 0 && other.z() != 0) {
        return Vector3(x() / other.x(), y() / other.y(), z() / other.z());
    }
    return *this;
}

Vector3& Vector3::operator+=(const Vector3 &other)
{
    if (this != &other) {
        _x += other.x();
        _y += other.y();
        _z += other.z();
    }
    return *this;
}

Vector3& Vector3::operator-=(const Vector3 &other)
{
    if (this != &other) {
        _x -= other.x();
        _y -= other.y();
        _z -= other.z();
    }
    return *this;
}

Vector3& Vector3::operator*=(const Vector3 &other)
{
    if (this != &other) {
        _x *= other.x();
        _y *= other.y();
        _z *= other.z();
    }
    return *this;
}

Vector3& Vector3::operator/=(const Vector3 &other)
{
    if (this != &other) {
        _x = (other.x() > 0) ? _x /= other.x() : _x;
        _y = (other.y() > 0) ? _y /= other.y() : _y;
        _z = (other.z() > 0) ? _z /= other.z() : _z;
    }
    return *this;
}

Vector3 Vector3::operator*(double value) const
{
    return Vector3(x() * value, y() * value, z() * value);
}

Vector3 Vector3::operator/(double value) const
{
    return Vector3(x() / value, y() / value, z() / value);
}

Vector3 Vector3::operator+(double value) const
{
    return Vector3(x() + value, y() + value, z() + value);
}

Vector3 Vector3::operator-(double value) const
{
    return Vector3(x() - value, y() - value, z() - value);
}

Vector3& Vector3::operator/=(double value) 
{
    if (value > 0) {
        _x /= value;
        _y /= value;
        _z /= value;
    }
    return *this;
}

Vector3& Vector3::operator*=(double value) 
{
    _x *= value;
    _y *= value;
    _z *= value;
    return *this;
}

Vector3 unit_vector(const Vector3& v) {
    return v / v.length();
}

Vector3 operator*(double scalar, const Vector3& v) {
    return v * scalar;
}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector3& v) {
    is >> v._x >> v._y >> v._z;
    return is;
}