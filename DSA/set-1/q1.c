#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the list
void appendNode(node** addHead, int data) {
    node* newNode = createNode(data);

    if (*addHead == NULL) {
        *addHead = newNode;
    } else {
        node* temp = *addHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node at a given index
void deleteNodeAtIndex(node** addHead, int index) {
    if (*addHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = *addHead;

    if (index == 0) {
        *addHead = temp->next;
        free(temp);
        return;
    }

    node* prev = NULL;
    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the 5th element of the list
void printFifthElement(node* head) {
    node* temp = head;
    for (int i = 0; i < 4; i++) {
        if (temp != NULL) {
            temp = temp->next;
        }
    }

    if (temp != NULL) {
        printf("The 5th element of the resulting list is: %d\n", temp->data);
    } else {
        printf("List has less than 5 elements.\n");
    }
}

// Function to print the entire list (for debugging or visualization)
void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;

    // Input 10 elements into the linked list
    printf("Enter 10 elements:\n");
    int data;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &data);
        appendNode(&head, data);
    }

    // Deleting the 3rd (index 2) and 6th (index 5) elements
    deleteNodeAtIndex(&head, 2); // Delete 3rd element
    deleteNodeAtIndex(&head, 4); // Delete 6th element (originally at index 5, but index shifts after first deletion)

    // Printing the 5th element of the resulting list
    printFifthElement(head);

    return 0;
}
