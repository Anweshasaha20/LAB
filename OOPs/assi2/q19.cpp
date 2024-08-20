#include <iostream>

class Vector {
private:
    int* data;   // Pointer to hold the array of integers
    int size;    // Size of the vector

public:
    // Constructor
    Vector(int s) {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;  // Initialize all elements to 0
        }
    }

    // Copy Constructor
    Vector(const Vector& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Addition function
    Vector add(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i]+ other.data[i];
        }
        return result;
    }

    // Subtraction function
    Vector subtract(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Equality function
    bool isEqual(const Vector& other) {
        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Less than function
    bool isLessThan(const Vector& other) {
        for (int i = 0; i < size; i++) {
            if (data[i] >= other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Greater than function
    bool isGreaterThan(const Vector& other) {
        for (int i = 0; i < size; i++) {
            if (data[i] <= other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Function to set an element of the vector
    void setElement(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    // Function to get an element of the vector
    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return -1;  // Error value if index is out of bounds
    }

    // Print the vector
    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector v1(3);
    v1.setElement(0, 1);
    v1.setElement(1, 2);
    v1.setElement(2, 3);

    Vector v2(3);
    v2.setElement(0, 4);
    v2.setElement(1, 5);
    v2.setElement(2, 6);

    Vector v3 = v1.add(v2);
    Vector v4 = v2.subtract(v1);

    std::cout << "v1: ";
    v1.print();

    std::cout << "v2: ";
    v2.print();

    std::cout << "v3 (v1 + v2): ";
    v3.print();

    std::cout << "v4 (v2 - v1): ";
    v4.print();

    std::cout << "v1 == v2: " << (v1.isEqual(v2) ? "True" : "False") << std::endl;
    std::cout << "v1 < v2: " << (v1.isLessThan(v2) ? "True" : "False") << std::endl;
    std::cout << "v2 > v1: " << (v2.isGreaterThan(v1) ? "True" : "False") << std::endl;

    return 0;
}
