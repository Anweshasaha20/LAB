#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

void addSparseMatrices(Element matrix1[], int size1, Element matrix2[], int size2, Element result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (matrix1[i].row == matrix2[j].row && matrix1[i].col == matrix2[j].col) {
            result[k].row = matrix1[i].row;
            result[k].col = matrix1[i].col;
            result[k].value = matrix1[i].value + matrix2[j].value;
            i++; j++; k++;
        } else if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result[k++] = matrix1[i++];
        } else {
            result[k++] = matrix2[j++];
        }
    }

    while (i < size1) {
        result[k++] = matrix1[i++];
    }

    while (j < size2) {
        result[k++] = matrix2[j++];
    }

    *sizeResult = k;
}

void printSparseMatrix(Element matrix[], int size) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < size; i++) {
        printf("Row: %d, Column: %d, Value: %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
    printf("\n");
}

int inputSparseMatrix(Element matrix[], const char *matrixName) {
    int rows, cols, size = 0;

    printf("Enter the dimensions of %s (e.g., 3*3): ", matrixName);
    scanf("%d*%d", &rows, &cols);

    printf("Enter the elements of %s row by row:\n", matrixName);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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
    Element matrix1[50], matrix2[50], result[100];
    int size1, size2, sizeResult;

    printf("Input for Matrix 1:\n");
    size1 = inputSparseMatrix(matrix1, "Matrix 1");

    printf("Input for Matrix 2:\n");
    size2 = inputSparseMatrix(matrix2, "Matrix 2");

    addSparseMatrices(matrix1, size1, matrix2, size2, result, &sizeResult);

    printf("Matrix 1:\n");
    printSparseMatrix(matrix1, size1);

    printf("Matrix 2:\n");
    printSparseMatrix(matrix2, size2);

    printf("Resultant Sparse Matrix after addition:\n");
    printSparseMatrix(result, sizeResult);

    return 0;
}
