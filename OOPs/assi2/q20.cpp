#include<iostream>
#include<algorithm>
using namespace std;
class intArray{
    int *arr;
    int size;

    public: 
    
    intArray(int s){
        size = s;
        arr = new int[size];
    }

    intArray(const intArray &t){
        size = t.size;
        arr = new int[size];
        for(int i = 0;i<size;i++){
            arr[i]=t.arr[i];
        }
    }
    ~intArray(){
        delete[] arr;
    }

    // Function to set an element of the vector
    void setElement(int index, int value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }

    // Function to get an element of the vector
    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        return -1;  // Error value if index is out of bounds
    }

     // Print the vector
    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    intArray add(const intArray &t){
        intArray temp(t.size);
        for(int i =0;i<t.size;i++){
            temp.arr[i]=arr[i]+t.arr[i];
        }
        return temp;
    }

    void reverse(){
        

        for(int i =0;i<size/2;i++){
            swap(arr[i],arr[size-1-i]);
        }
         

    }

     void sort(){
        
        for(int i =0;i<size;i++){
            int max=INT_MIN;
            int max_i=0;
            for(int j=i;j<size;j++){
               if(arr[j]>max){
                max=arr[j];
                max_i=j;
               }
            }

            swap(arr[i],arr[max_i]);
        }
         

    }





};

int main(){
     intArray v1(3);
    v1.setElement(0, 1);
    v1.setElement(1, 3);
    v1.setElement(2, 2);

    intArray v2(3);
    v2.setElement(0, 6);
    v2.setElement(1, 5);
    v2.setElement(2, 4);

    intArray v3 = v1.add(v2);
    
    v1.print();
    v2.print();
    v3.print();
    v3.reverse();
    v3.print();
    v3.sort();
    v3.print();
    
   
    


    return 0;
}