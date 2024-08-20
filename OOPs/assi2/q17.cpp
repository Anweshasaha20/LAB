#include<iostream>
using namespace std;
class rec{
    double l , b ;

    public:
    rec(double l,double b){
        this->l=l;
        this->b=b;
    }

    double area(){
        return (l*b);
    }

};

int main(){
    rec s1(4,6);
    rec s2(10,2);
    rec s3(9,6);
    rec s4(7,4);
    cout<<"Area of the rectangle s1: "<< s1.area()<<endl;
    cout<<"Area of the rectangle s2: "<< s2.area()<<endl;
    cout<<"Area of the rectangle s3: "<< s3.area()<<endl;
    cout<<"Area of the rectangle s4: "<< s4.area()<<endl;
   
}