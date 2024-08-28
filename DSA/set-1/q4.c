#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int evaluatePolynomial(node* poly, int x) {
    int result = 0;
    node* temp = poly;
    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
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

int main() {
    node* poly = NULL;
    
    insertNode(&poly, 5, 3);
    insertNode(&poly, 4, 2);
    insertNode(&poly, 2, 0);

    printf("Polynomial: ");
    printPolynomial(poly);

    int x;
    printf("Enter the value of x for evaluation: ");
    scanf("%d", &x);

    int result = evaluatePolynomial(poly, x);
    printf("Polynomial evaluated at x = %d is: %d\n", x, result);

    return 0;
}
