#include<stdio.h>
#define maxLength 10

void multiply(int poly1[],int n1,int poly2[],int n2,int res[]){
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            res[i+j]+=poly1[i]*poly2[j];
        }
    }
    
}

void display(int res[],int n){
    int bool=0;
    for(int i=0;i<n;i++){
        if(res[i]!=0){
            if(bool){
                printf(" + ");
                
            }
        printf("%dx^%d",res[i],i);
        bool=1;}
    }
    printf("\n");
}

int main(){
    int poly1[maxLength]={0};
    int poly2[maxLength]={0};
    int res[2*maxLength]={0};

    poly1[5] = 9;
    poly1[4] = 2;
    poly1[0] = 6;

    poly2[1] = 6;
    poly2[0] = 8;
    poly2[3] = 5;
    poly2[7] = 3;

    int n1 = 6;
    int n2 = 8;

    multiply(poly1,n1,poly2,n2,res);
    printf("Resultant Polynomial:");
    display(res,n1+n2-1);

}