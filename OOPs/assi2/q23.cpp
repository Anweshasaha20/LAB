#include <iostream>

class Complex {
private:
    float real;
    float img;

public:
    
    void setReal(float r) {
        real = r;
    }

    
    void setImg(float i) {
        img = i;
    }

    
    float getReal() const {
        return real;
    }

    
    float getImg() const {
        return img;
    }

    
    void disp() const {
        std::cout << real << " + " << img << "i" << std::endl;
    }

    
    Complex sum(const Complex& other) const {
        Complex result;
        result.real = this->real + other.real;
        result.img = this->img + other.img;
        return result;
    }
};

int main() {
   
    Complex c1, c2, c3;

    
    c1.setReal(3.5);
    c1.setImg(2.5);

    
    
    c2.setReal(1.5);
    c2.setImg(4.5);

    
    c3 = c1.sum(c2);

    
    std::cout << "Complex Number 1: ";
    c1.disp();

    std::cout << "Complex Number 2: ";
    c2.disp();

    std::cout << "Sum (Complex Number 3): ";
    c3.disp();

    return 0;
}
