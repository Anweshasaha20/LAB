#include <stdio.h>

int main() {
    int m, n;
    int i, j; // Declare i, j outside the for loops

    // Take the dimensions of the 2D array as input
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    int array_2d[m][n];
    int array_1d[m * n];

    // Take the 2D array elements as input
    printf("Enter the elements of the 2D array:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Element at (%d, %d): ", i, j);
            scanf("%d", &array_2d[i][j]);
        }
    }

    // Convert 2D array to 1D array
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int index_1d = i * n + j;
            array_1d[index_1d] = array_2d[i][j];
        }
    }

    // Print the 2D array elements along with their corresponding 1D array values
    printf("\n2D Array and corresponding 1D Array values:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int index_1d = i * n + j;
            printf("Element at (%d, %d) in 2D array is %d in 1D array\n", i, j, array_1d[index_1d]);
        }
    }

    return 0;
}
