import <iostream>;

import Math.Space;

using namespace std;
using namespace Math;


int main() {
    std::cout << "Hello World!" << std::endl;

    Point p1 = Point::randomPoint();
    printf("<%.2f, %.2f, %.2f>\n", p1.x, p1.y, p1.z);
    Point p2 = Point::randomPoint();
    printf("<%.2f, %.2f, %.2f>\n", p2.x, p2.y, p2.z);
    Point p3 = Point::randomPoint();
    printf("<%.2f, %.2f, %.2f>\n", p3.x, p3.y, p3.z);

    Vector v = p1 - p2;
    printf("<%.2f, %.2f, %.2f>\n", v.x, v.y, v.z);

    for(int i=0; i<1000; ++i) {
        Vector rv = Vector::randomVector();
        printf("<%3.0f, %3.0f, %3.0f>\n", rv.x, rv.y, rv.z);
    }
}