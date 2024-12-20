#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *array;
    int top;
} Stack;

void enqueue(int data, Stack **stack1, Stack **stack2)
{
    while ((*stack1)->top != -1)
    {
        (*stack2)->top++;
        (*stack2)->array[(*stack2)->top] = (*stack1)->array[(*stack1)->top];
        (*stack1)->top--;
    }
    (*stack1)->top++;
    (*stack1)->array[(*stack1)->top] = data;
    while ((*stack2)->top != -1)
    {
        (*stack1)->top++;
        (*stack1)->array[(*stack1)->top] = (*stack2)->array[(*stack2)->top];
        (*stack2)->top--;
    }
}

void dequeue(Stack **stack1)
{
    if ((*stack1)->top == -1)
    {
        printf("UnderFlow\n");
        return;
    }
    printf("Dequeued element: %d\n", (*stack1)->array[(*stack1)->top]);
    (*stack1)->top--;
}

void print(Stack *stack1)
{
    if (stack1->top == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= stack1->top; i++)
    {
        printf("%d ", stack1->array[i]);
    }
    printf("\n");
}

int main()
{
    Stack *stack1 = (Stack *)malloc(sizeof(Stack));
    stack1->array = (int *)malloc(100 * sizeof(int));
    stack1->top = -1;
    Stack *stack2 = (Stack *)malloc(sizeof(Stack));
    stack2->array = (int *)malloc(100 * sizeof(int));
    stack2->top = -1;
    
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            enqueue(data, &stack1, &stack2);
            break;
        case 2:
            dequeue(&stack1);
            break;
        case 3:
            print(stack1);
            break;
        case 4:
            printf("Exiting...\n");
            free(stack1->array);
            free(stack2->array);
            free(stack1);
            free(stack2);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
