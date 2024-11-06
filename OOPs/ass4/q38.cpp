#include<iostream>
using namespace std;

class complex{
    float real,img;
    public:
    complex(float a=0,float b=0):real(a),img(b){};
    ~complex(){};
    friend ostream& operator<<(ostream& os,const complex &c){
        if(c.img>=0)
        os<<c.real<<"+"<<c.img<<"i"<<endl;
        else{
             os<<c.real<<c.img<<"i"<<endl;
        }
        return os;
    }

    complex operator +(complex &a){
        complex temp;
        temp.real=real+a.real;
        temp.img=img+a.img;
        return temp; 
    }
     complex operator -(complex &a){
        complex temp;
        temp.real=real-a.real;
        temp.img=img-a.img;
        return temp; 
    }
     complex operator *(complex &a){
        complex temp;
        temp.real=(real*a.real)+(img*a.img);
        temp.img=(real*a.img)+(img*a.real);
        return temp; 
    }
     complex operator /(complex &a){
        complex temp;
        float denominator=(a.real*a.real)+(a.img*a.img);
        temp.real=(real*a.real)+(img*a.img)/denominator;
        temp.img=(real*a.img)+(img*a.real)/denominator;
        return temp; 
    }

};

class quadratic{
   public:
   float a,b,c;
   
   quadratic(float x=0,float y=0, float z=0):a(x),b(y),c(z){};

   friend ostream& operator <<(ostream& os,const quadratic &s);

   friend istream& operator >>(istream& is,quadratic &q);

   quadratic operator +(quadratic &s){
      return quadratic(a+s.a,b+s.b,c+s.c);
   }
   
    float eval(float x){
    return (a*x*x)+(b*x)+c;
    }

    void computeRoots(complex& root1, complex& root2) {
        float discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
           
            float r1 = (-b + sqrt(discriminant)) / (2 * a);
            float r2 = (-b - sqrt(discriminant)) / (2 * a);
            root1 = complex(r1, 0);
            root2 = complex(r2, 0);
        } else if (discriminant == 0) {
           
            float r = -b / (2 * a);
            root1 = complex(r, 0);
            root2 = complex(r, 0);
        } else {
            
            float realPart = -b / (2 * a);
            float imagPart = sqrt(-discriminant) / (2 * a);
            root1 = complex(realPart, imagPart);
            root2 = complex(realPart, -imagPart);
        }
    }
};


ostream& operator <<(ostream& os,const quadratic& s){
    
    os<<s.a<<"x^2+("<<s.b<<")x+("<<s.c<<")"<<endl;
    return os;
    
   };
istream& operator >>(istream& is,quadratic& q){
     cout << "Enter coefficient a: ";
    is >> q.a;
    cout << "Enter coefficient b: ";
    is >> q.b;
    cout << "Enter coefficient c: ";
    is >> q.c;
    return is;
}

int main(){
    quadratic q1, q2;
    
   
    cout << "Enter first polynomial:\n";
    cin >> q1;
    cout<<q1;
    cout << "Enter second polynomial:\n";
    cin >> q2;
    cout<<q2;

  
    quadratic sum = q1 + q2;
    cout << "Sum of polynomials: " << sum << endl;

    
    float x;
    cout << "Enter a value of x to evaluate the polynomial 1 : ";
    cin >> x;
    cout << "Value of the polynomial at x = " << x << ": " << q1.eval(x) << endl;

    
    complex root1, root2;
    if (q1.a != 0) { // Ensure it's a quadratic equation
        q1.computeRoots(root1, root2);
        cout << "Roots of the polynomial " << q1 << " are: " << root1 << " and " << root2 << endl;
    } else {
        cout << "Not a quadratic equation." << endl;
    }

    return 0;
}