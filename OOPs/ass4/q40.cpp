
#include <iostream>
#include <stdexcept> // Include the header for std::out_of_range
using namespace std;

class IntArray {
private:
    int* arr;  
    int size; 

public:
   
    IntArray(int s) : size(s) {
        arr = new int[size]; 
    }

    ~IntArray() {
        delete[] arr; 
    }

  int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds"); 
        }
        return arr[index]; 
    }

    friend ostream& operator<<(ostream& os, const IntArray& intArray) {
        for (int i = 0; i < intArray.size; ++i) {
            os << intArray.arr[i] << " "; 
        }
        return os; 
    }
};

int main() {
IntArray i(10);
for(int k = 0; k < 10; k++)
i[k] = k;
cout << i;

return 0;
}