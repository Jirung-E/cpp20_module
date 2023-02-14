module Math.Space;

import :Vector;
import Math.Random;
import <cmath>;

using namespace Math;


Vector::Vector(const double& x, const double& y, const double& z) : x { x }, y { y }, z { z } {

}


Vector Vector::operator+(const Vector& other) const {
    return Vector { x + other.x, y + other.y, z + other.z };
}

Vector Vector::operator-(const Vector& other) const {
    return Vector { x - other.x, y - other.y, z - other.z };
}

Vector Vector::operator/(const double& value) const {
    return Vector { x / value, y / value, z / value };
}

Vector Vector::operator*(const double& value) const {
    return Vector { x * value, y * value, z * value };
}


double Vector::length() const {
    return sqrt(x*x + y*y + z*z);
}

Vector Vector::getNormalized() const {
    if(length() == 0.0) {
        return *this;
    }
    return *this/length();
}

Vector Math::Vector::randomVector() {
    return Vector { random(-100.0, 100.0), random(-100.0, 100.0), random(-100.0, 100.0) };
}