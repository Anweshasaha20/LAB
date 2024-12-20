#include <stdio.h>
#include <math.h>

int i;
typedef struct {
    int coefficient;
    int exponent;
} Term;

int evaluateSparsePolynomial(Term poly[], int size, int x) {
    int result = 0;
    for (i = 0; i < size; i++) {
        result += poly[i].coefficient * pow(x, poly[i].exponent);
    }
    return result;
}

int main() {
    Term poly[10];  // Array to hold up to 10 terms
    int size, x;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &size);

    printf("Enter the terms (coefficient and exponent) of the polynomial:\n");
    for (i = 0; i < size; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &poly[i].coefficient);
        printf("Exponent: ");
        scanf("%d", &poly[i].exponent);
    }

    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = evaluateSparsePolynomial(poly, size, x);
    printf("Result: %d\n", result);

    return 0;
}
