#include <stdio.h>
#include <stdlib.h>

int i, j, k;

typedef struct {
    int coefficient;
    int exponent;
} Term;

void addSparsePolynomials(Term poly1[], int size1, Term poly2[], int size2, Term result[], int *sizeResult) {
    i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (poly1[i].exponent == poly2[j].exponent) {
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            result[k].exponent = poly1[i].exponent;
            i++; j++; k++;
        } else if (poly1[i].exponent > poly2[j].exponent) {
            result[k++] = poly1[i++];
        } else {
            result[k++] = poly2[j++];
        }
    }

    while (i < size1) {
        result[k++] = poly1[i++];
    }

    while (j < size2) {
        result[k++] = poly2[j++];
    }

    *sizeResult = k;
}

void printPolynomial(Term poly[], int size) {
    for (i = 0; i < size; i++) {
        if (i > 0 && poly[i].coefficient > 0) printf(" + ");
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
    }
    printf("\n");
}

int main() {
    Term poly1[10], poly2[10], result[20];
    int size1, size2, sizeResult;

    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &size1);

    printf("Enter the terms (coefficient and exponent) for the first polynomial:\n");
    for (i = 0; i < size1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly1[i].coefficient, &poly1[i].exponent);
    }

    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &size2);

    printf("Enter the terms (coefficient and exponent) for the second polynomial:\n");
    for (i = 0; i < size2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly2[i].coefficient, &poly2[i].exponent);
    }

    addSparsePolynomials(poly1, size1, poly2, size2, result, &sizeResult);

    printf("Resultant polynomial: ");
    printPolynomial(result, sizeResult);

    return 0;
}
