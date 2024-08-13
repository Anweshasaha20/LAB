 #include<iostream>
 using namespace std;

 char* strcpy(char* const target,const char* const src){
    int i=0;
    for( i=0;src[i]!='\0';i++){
        target[i]=src[i];
    }
     target[i] = '\0'; 
    return target;
 }
 int main(){
    char src[50] ;
    cout << "Enter a string: ";
    cin.getline(src,50);
    char target[50];

    cout<<"copied string:"<<strcpy(target,src)<<endl;
    


    return 0;
 }
