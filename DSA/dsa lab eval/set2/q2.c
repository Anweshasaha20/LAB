#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function to create a circular linked list
struct node *createCircularLinkedList(int n)
{
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 1; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head;  // Make it circular
    return head;
}

// Function to find the survivor in the Josephus problem
int josephus(struct node *head, int k)
{
    struct node *ptr1 = head, *ptr2 = head;
    while (ptr1->next != ptr1)  // Continue until only one node remains
    {
        int count = 1;
        while (count != k)  // Move ptr1 k-1 steps forward
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }
        ptr2->next = ptr1->next;  // Remove the kth person
        ptr1 = ptr2->next;  // Move ptr1 to the next person
    }
    int result = ptr1->data;  // The survivor
    return result;
}

int main()
{
    int n, k;

    // Taking user input for the number of people and the step value
    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step value (k): ");
    scanf("%d", &k);

    // Create the circular linked list and solve the Josephus problem
    struct node *head = createCircularLinkedList(n);
    int survivor = josephus(head, k);
    
    printf("The survivor is person %d\n", survivor);
    
    return 0;
}
