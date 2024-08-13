 #include <iostream>
 using namespace std;


int factorial(const int& n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num ;
    cout<<"Enter a no.:"<<endl;
    cin>>num; 
    int result = factorial(num);  

    cout << "Factorial of " << num << " is: " << result << endl;

    return 0;
}

