#include <iostream>
using namespace std;
class point{
    float x,y;
    public:
   
    point(float a=0,float b=0):x(a),y(b){};
    ~point(){
        cout<<"destructor is called"<<endl;
    }
    void print(){
        cout<<"("<<x<<","<<y<<")";
    }

    float operator -(point &a){
       float dist=sqrt(pow((x-a.x),2)+pow((y-a.y),2));
       return dist;
    }

};

int main(){
    point a(6,7);
    point b(1,1);
    cout<<"Dist between ";a.print();cout<<" and ";b.print();cout<<" is: "<<a-b<<endl;
    
}