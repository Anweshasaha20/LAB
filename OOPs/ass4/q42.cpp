#include<iostream>
using namespace std;
class table{
    int r,c;
    vector<vector<float>>data;
    public:
    table(int a,int b):r(a),c(b),data(r,vector<float>(c,0)){};
    friend istream& operator >>(istream& is,table &s){
        for(int i=0;i<s.r;i++){
            for(int j=0;j<s.c;j++){
                is>>s.data[i][j];
            }
        }
        return is;
    }
    vector<float>& operator [](int index){
        return data[index];
    }
    
    table& operator =(table& s){
        if (this != &s) { 
            r= s.r;
            c = s.c;
            data = s.data; 
        }
        return *this;
    }
friend ostream& operator <<(ostream& os,table &s){
        for(int i=0;i<s.r;i++){
            for(int j=0;j<s.c;j++){
                os<<s.data[i][j];
            }
            os<<"\n";
        }
        return os;
    }
     

};
int main(){
table t(4, 5), t1(4, 5);
cout<<"Enter values for table t(4,5):";
cin >> t;
t[0][0] = 5;
int x = t[2][3];
t1 = t;
cout << t << "\n" << t1 << x;
}