#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

void countNonZeroElements(Element matrix[], int size, int rows) {
    for (int i = 0; i < rows; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (matrix[j].row == i && matrix[j].value != 0) {
                count++;
            }
        }
        printf("Row %d has %d non-zero elements.\n", i, count);
    }
}

int inputSparseMatrix(Element matrix[], int *rows, int *cols) {
    printf("Enter the matrix dimensions (e.g., 3*3): ");
    scanf("%d*%d", rows, cols);

    printf("Enter the elements of the %d*%d matrix row by row:\n", *rows, *cols);

    int size = 0;
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            int value;
            scanf("%d", &value);

            if (value != 0) {
                matrix[size].row = i;
                matrix[size].col = j;
                matrix[size].value = value;
                size++;
            }
        }
    }

    return size;
}

int main() {
    Element matrix[50]; // Maximum number of non-zero elements
    int rows, cols, size;

    size = inputSparseMatrix(matrix, &rows, &cols);
    countNonZeroElements(matrix, size, rows);

    return 0;
}
