#include <iostream>
using namespace std;


inline int add(int a, int b = 0, int c = 0) {
    return a + b + c;
}

int main() {
    int result;
    int a,b,c;
    cout<<"Enter 3 no.:"<<endl;
    cin>>a>>b>>c;
    
    result = add(a,b,c);
    cout << "Sum of "<<a<<","<< b <<","<<c <<":"<< result << endl;

    
    result = add(a,b);
     cout << "Sum of "<<a<<","<< b  <<":"<< result << endl;

    
    result = add(a);
     cout << "Sum of "<<a<<":"<< result << endl;

    return 0;
}
