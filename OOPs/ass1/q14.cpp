#include <iostream>
using namespace std;


void print(int arr[], int size) {
    cout << "Vector elements: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void print(int** arr, int rows, int cols) {
    cout << "Matrix elements:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    
    int vectorSize;
    cout << "Enter the size of the vector: ";
    cin >> vectorSize;

    int* vector = new int[vectorSize];
    cout << "Enter the elements of the vector: ";
    for(int i = 0; i < vectorSize; i++) {
        cin >> vector[i];
    }

    
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }


    print(vector, vectorSize);

    
    print(matrix, rows, cols);

    // Clean up dynamic memory
    delete[] vector;
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
