#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;
node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
// Function to append a node at the end of the list
void appendNode(node** addHead,int data){
    node* newNode = createNode(data);
   
    if(*addHead==NULL){
        *addHead=newNode;
        return;
    }
    
    node* temp = *addHead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printList(node* head){
    node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverse(node **addhead){
    node* prev=NULL;
    node* current=*addhead;
    node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *addhead=prev;

}
int main(){
    node* head=NULL;
    int data;
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        appendNode(&head, data);
    }
    

    printf("Original list:\n");
    printList(head);
    printf("Reversed list:\n");
    reverse(&head);
    printList(head);
}