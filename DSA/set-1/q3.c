#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node* next;
} node;

node* createNode(int coeff, int exp) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node** poly, int coeff, int exp) {
    node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printPolynomial(node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

node* addPolynomials(node* poly1, node* poly2) {
    node* result = NULL;
    node* temp1 = poly1;
    node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp > temp2->exp) {
            insertNode(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp1->exp < temp2->exp) {
            insertNode(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else {
            int sumCoeff = temp1->coeff + temp2->coeff;
            if (sumCoeff != 0) {
                insertNode(&result, sumCoeff, temp1->exp);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insertNode(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertNode(&result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

int main() {
    node* poly1 = NULL;
    node* poly2 = NULL;

    insertNode(&poly1, 5, 3);
    insertNode(&poly1, 4, 2);
    insertNode(&poly1, 2, 0);

    insertNode(&poly2, 3, 3);
    insertNode(&poly2, 4, 1);
    insertNode(&poly2, 1, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    node* result = addPolynomials(poly1, poly2);

    printf("Sum of polynomials: ");
    printPolynomial(result);

    return 0;
}
