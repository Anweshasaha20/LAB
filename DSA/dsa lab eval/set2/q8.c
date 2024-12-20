#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void createCircular(Node **head, int n)
{
    *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    tail->next = *head;
}

void insertAtPosition(Node **head, int data, int position)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (position == 1)
    {
        Node *temp1 = *head;
        while (temp1->next != *head)
        {
            temp1 = temp1->next;
        }
        temp->next = *head;
        temp1->next = temp;
        *head = temp;
    }
    else
    {
        Node *temp1 = *head;
        for (int i = 0; i < position - 2; i++)
        {
            temp1 = temp1->next;
            if (temp1 == *head)
            {
                printf("Invalid position\n");
                return;
            }
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

void deleteAtPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    if (position == 1)
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        if (temp == *head)
        {
            *head = NULL;
        }
        else
        {
            Node *temp1 = *head;
            *head = temp1->next;
            temp->next = *head;
        }
    }
    else
    {
        int c = 0;
        Node *temp = *head;
        for (int i = 0; i < position - 2; i++)
        {
            c++;
            temp = temp->next;
            if (temp == *head)
            {
                printf("Underflow\n");
                return;
            }
        }
        Node *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}

void display(Node *head)
{
    Node *temp = head;
    int c = 0;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    do
    {
        printf("%d ", temp->data);
        c++;
        temp = temp->next;
    } while (temp != head);
    printf("\nNumber of nodes: %d\n", c);
}

int main()
{
    Node *head = NULL;
    int choice, data, position, n;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Insert at Position\n");
        printf("3. Delete at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            createCircular(&head, n);
            break;
        case 2:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insertAtPosition(&head, data, position);
            break;
        case 3:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 4:
            display(head);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
