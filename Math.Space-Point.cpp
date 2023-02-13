module Math.Space;

import :Point;
import Math.Random;

using namespace Math;


Point::Point(const double& x, const double& y, const double& z) : x { x }, y { y }, z { z } {

}

Vector Math::Point::operator-(const Point& other) {
    return Vector { x - other.x, y - other.y, z - other.z };
}

Point Math::Point::operator+(const Vector& vector) {
    return Point { x + vector.x, y + vector.y, z + vector.z };
}

Point Math::Point::operator-(const Vector& vector) {
    return Point { x - vector.x, y - vector.y, z - vector.z };
}

Point Point::randomPoint() {
    return Point { random(-100.0, 100.0), random(-100.0, 100.0), random(-100.0, 100.0) };
}