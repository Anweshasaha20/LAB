#include <stdio.h>
#include <stdlib.h>

int i, j, k;

struct Term {
    int coeff;   // Coefficient
    int exp;     // Exponent
};

void multiplyPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[], int *res_size) {
    *res_size = 0;

    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            int coeff = poly1[i].coeff * poly2[j].coeff;
            int exp = poly1[i].exp + poly2[j].exp;

            int found = 0;
            for (k = 0; k < *res_size; k++) {
                if (result[k].exp == exp) {
                    result[k].coeff += coeff;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                result[*res_size].coeff = coeff;
                result[*res_size].exp = exp;
                (*res_size)++;
            }
        }
    }
}

void printPolynomial(struct Term poly[], int n) {
    for (i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i < n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int n1, n2;

    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &n1);
    struct Term poly1[n1];

    printf("Enter the terms of Polynomial 1 (coefficient and exponent):\n");
    for (i = 0; i < n1; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &poly1[i].coeff);
        printf("Exponent: ");
        scanf("%d", &poly1[i].exp);
    }

    printf("Enter the number of terms in Polynomial 2: ");
    scanf("%d", &n2);
    struct Term poly2[n2];

    printf("Enter the terms of Polynomial 2 (coefficient and exponent):\n");
    for (i = 0; i < n2; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &poly2[i].coeff);
        printf("Exponent: ");
        scanf("%d", &poly2[i].exp);
    }

    struct Term result[n1 * n2];
    int res_size;

    multiplyPolynomials(poly1, n1, poly2, n2, result, &res_size);

    printf("Polynomial 1: ");
    printPolynomial(poly1, n1);

    printf("Polynomial 2: ");
    printPolynomial(poly2, n2);

    printf("Resultant Polynomial after multiplication: ");
    printPolynomial(result, res_size);

    return 0;
}
