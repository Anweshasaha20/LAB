#include <iostream>
using namespace std;

class Integer {
private:
    int value; 

public:
    
    Integer(int v = 0) : value(v) {}

   
    Integer(const Integer& other) : value(other.value) {}

    
    Integer operator+(const Integer& other) const {
        return Integer(value + other.value); 
    }

   
    Integer operator++(int) { 
        Integer temp = *this; 
        value++; 
        return temp; 
    }

   
    Integer& operator=(const Integer& other) {
        if (this != &other) { 
            value = other.value;
        }
        return *this; 
    }

   
    operator int() const {
        return value; 
    }

   
    friend ostream& operator<<(ostream& os, const Integer& integer) {
        os << integer.value; 
        return os;
    }
};

int main() {
    Integer a = 4, b = a, c;
    c = a + b++;
    int i = a;
    cout << a << " " << b << " " << c << endl; // Add spaces for clarity
    return 0;
}
