export module Math.Space:Point;

import :Vector;


namespace Math {
    export class Point {
    public:
        double x;
        double y;
        double z;

    public:
        Point() = default;
        Point(const double& x, const double& y, const double& z);
        Vector operator-(const Point& other);
        Point operator+(const Vector& vector);
        Point operator-(const Vector& vector);
        
    public:
        static Point randomPoint();
    };
}