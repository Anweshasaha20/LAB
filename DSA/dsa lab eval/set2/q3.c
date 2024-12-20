#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtPosition(struct node **head_ref, int position, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 1)
    {
        newNode->next = *head_ref;
        if (*head_ref != NULL)
            (*head_ref)->prev = newNode;
        *head_ref = newNode;
        return;
    }

    struct node *temp = *head_ref;
    int i = 1;
    while (i < position - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtPosition(struct node **head_ref, int position)
{
    struct node *temp = *head_ref;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position == 1)
    {
        *head_ref = temp->next;
        if (*head_ref != NULL)
            (*head_ref)->prev = NULL;
        free(temp);
        return;
    }

    int i = 1;
    while (i < position && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
}

void countNodes(struct node *head)
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
}

void reversePrint(struct node *head)
{
    if (head == NULL)
        return;
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

struct node *reverse(struct node *head)
{
    struct node *temp = NULL;
    struct node *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

int main()
{
    struct node *head = NULL;
    int choice, position, data;

    do
    {
        // Menu for the user to choose an option
        printf("\nMenu:\n");
        printf("1. Insert at Position\n");
        printf("2. Delete at Position\n");
        printf("3. Print List\n");
        printf("4. Reverse List\n");
        printf("5. Reverse Print\n");
        printf("6. Count Nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter position to insert at: ");
            scanf("%d", &position);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtPosition(&head, position, data);
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 3:
            printf("List: ");
            print(head);
            break;
        case 4:
            head = reverse(head);
            printf("Reversed List: ");
            print(head);
            break;
        case 5:
            printf("Reverse Print: ");
            reversePrint(head);
            break;
        case 6:
            countNodes(head);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
