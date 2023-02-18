export module Math.Space:Vector;


namespace Math {
    export class Vector {
    public:
        double x;
        double y;
        double z;

    public:
        Vector() = default;
        Vector(const double& x, const double& y, const double& z=0);
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator/(const double& value) const;
        Vector operator*(const double& value) const;

    public:
        double length() const;
        Vector getNormalized() const;
        
        static Vector randomVector();
    };
}