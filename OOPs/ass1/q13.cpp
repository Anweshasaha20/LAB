#include <iostream>
using namespace std;


int findMax(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}


int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int x, y, z;
    
    
    cout << "Enter three integers (x, y, z): ";
    cin >> x >> y >> z;
    cout << "Maximum of " << x << ", " << y << ", and " << z << " is: " << findMax(x, y, z) << endl;

    
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;
    
    int arr[size];
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Maximum element in the array is: " << findMax(arr, size) << endl;

    return 0;
}
