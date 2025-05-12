#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <array>

class Vector3 {
    public:
        // constructors & destructors
        Vector3();
        Vector3(double x, double y, double z);
        ~Vector3();
        // methods
        double length() const;
        double dot(const Vector3 &other) const;
        // vector operators
        Vector3 operator=(const Vector3 &other);
        Vector3 operator+(const Vector3 &other) const;
        Vector3 operator-(const Vector3 &other) const;
        Vector3 operator*(const Vector3& other) const;
        Vector3 operator/(const Vector3& other) const;
        Vector3& operator+=(const Vector3& other);
        Vector3& operator-=(const Vector3& other);
        Vector3& operator*=(const Vector3& other);
        Vector3& operator/=(const Vector3& other);
        Vector3 operator/(double value) const;
        Vector3 operator*(double value) const;
        Vector3 operator+(double value) const;
        Vector3 operator-(double value) const;
        Vector3& operator/=(double value);
        Vector3& operator*=(double value);
        friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
        friend std::istream& operator>>(std::istream& is, Vector3& v);
        friend Vector3 operator*(double scalar, const Vector3& v);
        double x() const { return _x; }
        double y() const { return _y; }
        double z() const { return _z; }
    private:
        // local vars
        double _x;
        double _y;
        double _z;
};
Vector3 unit_vector(const Vector3& v);
using point3 = Vector3;