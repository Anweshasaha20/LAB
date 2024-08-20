#include <iostream>
#include <cmath>
using namespace std;

class Point3D {
private:
    double x, y, z;

public:
    
    Point3D(double x, double y, double z)  {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    

    
    double distance(const Point3D& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    }

   
    void print() const {
        std::cout << "Point(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main() {
    
    Point3D p1(1.0, 2.0, 3.0);
    Point3D p2(4.0, 5.0, 6.0);

    double dist = p1.distance(p2);
    cout << "The distance between the two points is: " << dist << endl;

    return 0;
}
