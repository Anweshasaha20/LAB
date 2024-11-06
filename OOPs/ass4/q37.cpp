#include<iostream>
using namespace std;
class complex{
    float real,img;
    public:
    complex(float a=0,float b=0):real(a),img(b){};
    ~complex(){
        cout<<"destructor is called"<<endl;
    }
    void display(){
        if(img>=0)
        cout<<real<<"+"<<img<<"i"<<endl;
        else{
             cout<<real<<img<<"i"<<endl;
        }
    }

    complex operator +(complex &a){
        complex temp;
        temp.real=real+a.real;
        temp.img=img+a.img;
        return temp; 
    }
     complex operator -(complex &a){
        complex temp;
        temp.real=real-a.real;
        temp.img=img-a.img;
        return temp; 
    }
     complex operator *(complex &a){
        complex temp;
        temp.real=(real*a.real)+(img*a.img);
        temp.img=(real*a.img)+(img*a.real);
        return temp; 
    }
     complex operator /(complex &a){
        complex temp;
        float denominator=(a.real*a.real)+(a.img*a.img);
        temp.real=(real*a.real)+(img*a.img)/denominator;
        temp.img=(real*a.img)+(img*a.real)/denominator;
        return temp; 
    }

};

int main(){
       complex num1(4, 5);  
       complex num2(3, -2); 

    
    cout << "Number 1: ";
    num1.display();
    cout << "Number 2: ";
    num2.display();
    
    complex add = num1+num2;
    complex sub = num1-num2;
    complex mul = num1*num2;
    complex div = num1 / num2;

   
   cout << "Result of addition: ";
    add.display();
    cout << "Result of subtraction: ";
    sub.display();
    cout << "Result of multiplication: ";
    mul.display();
    cout << "Result of division: ";
    div.display();

    return 0;
}
