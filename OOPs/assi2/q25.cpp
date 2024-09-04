#include<iostream>
using namespace std;
 class Queue {
int *data;
int front, rear,size;
public :
Queue(int size){

  data = new int[size];
   front = -1;
   rear = -1;
   this->size=size;
  

} //create queue with specified size

void add(int value){
    if(rear + 1 == size){
        cout<<"Queue is full"<<endl;
        
    }
    else{
    rear++;
    data[rear]=value;}
}//add specified element to the queue

int remove(){
    if(rear== -1){
        cout<<"Quene is empty"<<endl;
        return -1;
    }
    front++;
    return data[front];
    }//delete element from the queue

void disp(){
    for(int i=front+1;i<=rear;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
} //displays all elements in the queue(front to rear order)

};
int main(){
    Queue q1(10) ;
    q1.add(2);
    q1.add(3);
    q1.add(4);
    q1.add(5);
    q1.remove();
    q1.remove();
    q1.disp();

}