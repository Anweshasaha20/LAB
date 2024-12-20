#include <stdio.h>
#include <stdlib.h>

int i, j;

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position
void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at a specific position
void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to count the number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Recursive function to reverse print the list
void reversePrintUtil(struct Node* head) {
    if (head == NULL) return;
    reversePrintUtil(head->next);
    printf("%d -> ", head->data);
}

// Function to reverse print the list
void reversePrint(struct Node* head) {
    reversePrintUtil(head);
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to drive the program
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Count Nodes\n");
        printf("4. Reverse Print\n");
        printf("5. Reverse List\n");
        printf("6. Print List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertNode(&head, data, position);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;

            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;

            case 4:
                printf("Reverse Print: ");
                reversePrint(head);
                break;

            case 5:
                reverseList(&head);
                printf("List has been reversed.\n");
                break;

            case 6:
                printf("Current List: ");
                printList(head);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
