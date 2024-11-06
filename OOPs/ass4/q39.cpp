#include<iostream>
using namespace std;


class INT {
int i;

public :
INT(int a=0):i(a){}
~INT() {};
friend ostream& operator <<(ostream& a,const INT s){
   a<<s.i<<endl;
   return a;
}
INT operator ++(){
    return INT(++i);
}

INT operator++(int) {
        return INT(i++);
        
    }
//This operator allows an object of a class to be implicitly converted to an int    
operator int()  {
        return i; 
    }    
};

int main() {
int x = 3;
INT y = x;//INT Y(X)
y++ = ++y;
x = y;
cout<<x;
return 0;
}