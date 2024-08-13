#include <iostream>
using namespace std;


inline int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int x , y, z ;
    cout<<"Enter  3 no.:"<<endl;
    
    cin>>x >>y>>z;



    
    int result = add(x, y, z);

    
    cout << "The sum is: " << result << endl;

    return 0;
}
