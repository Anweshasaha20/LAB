#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;

}node;
node* createNode(int data){
    node* newNode =(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->lchild=NULL;
    newNode->rchild=NULL;
    return newNode;
}

int findPos(int ele,int in[],int n){
    for(int i=0;i<n;i++){
        if(in[i]==ele)return i;
    }
    return -1;
}
node* solve(int in[],int pre[],int *index,int inorderStart,int inorderEnd,int n){
  if(*index>=n || inorderStart>inorderEnd){
    return NULL;
  }
  int ele=pre[*index];
      (*index)++;

  node* root = createNode(ele);
  int pos=findPos(ele,in,n);
  //recursive calls
  root->lchild=solve(in,pre,index,inorderStart,pos-1,n);
  root->rchild=solve(in,pre,index,pos+1,inorderEnd,n);
  return root;

}

node* buildTree(int in[],int pre[],int n){
    int preOrderIndex=0;
    node* ans=solve(in,pre,&preOrderIndex,0,n-1,n);
    return ans;
}
void postorder(struct node* root){
    if(root==NULL)return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
    return;
}
int main(){
    printf("Enter no. of ele:\n");
    int n;
    scanf("%d",&n);
    int in[n];
     printf("Enter inorder:\n");
    for (int i = 0; i < n; i++)
    {
          
         scanf("%d",&in[i]);
    }
    int pre[n];
     printf("Enter preorder\n");
     for (int i = 0; i < n; i++)
    {
          
         scanf("%d",&pre[i]);
    }
    node* root=NULL;
    root=buildTree(in,pre,n);
    printf("postorder:");
    postorder(root);


}