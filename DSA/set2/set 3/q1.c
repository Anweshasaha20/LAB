#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(){
    struct node* newNode = (struct node*)malloc(sizeof(struct  node));
    int x;
    printf("enter a no(-1 for no node):\n");
    scanf("%d",&x);
    newNode->data=x;
    if(x==-1)return NULL;
    printf("Enter a no. to the left of %d\n",x);
    newNode->left = create();
    printf("Enter a no. to the right of %d\n",x);
     newNode->right = create();
    return newNode;

   
}
void inorder(struct node* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    return;
}
void preorder(struct node* root){
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}
void postorder(struct node* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
    return;
}

int main(){
    struct node* root=NULL;
    // root = create();
    // inorder(root);
    // printf("\n");
    // preorder(root);
    //   printf("\n");
    // postorder(root);
    //   printf("\n");

     int choice;
      while (1) {
        printf("\nMenu:\n");
        printf("1. Create a binary tree\n");
        printf("2. In-order traversal\n");
        printf("3. Pre-order traversal\n");
        printf("4. Post-order traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root=create();
                break;
            case 2:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    
}