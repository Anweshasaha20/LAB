class Complex{
    int real;
    int imaginary;

    public Complex(int real, int imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }
    public Complex(int real) {
        this.real = real;
        this.imaginary = 0;
    }
    public Complex() {
        this.real = 0;
        this.imaginary = 0;
    }

    public Complex add(Complex other) {
        return new Complex(this.real + other.real, this.imaginary + other.imaginary);
    }

   
    public Complex multiply(Complex other) {
        int real = this.real * other.real + this.imaginary * other.imaginary;
        int imaginary = this.real * other.imaginary + this.imaginary * other.real;
        return new Complex(real, imaginary);
        
    }

   
    public void display() {
        if (imaginary >= 0) {
            System.out.println(real + "+" + imaginary + "i");
        } else {
            System.out.println(real + "" + imaginary + "i");
        }
    }

    
    public static void main(String[] args) {
       
        Complex num1 = new Complex(3, 2);
        Complex num2 = new Complex(4, -2);

       
        System.out.println("First Complex Number:");
        num1.display();
        System.out.println("Second Complex Number:");
        num2.display();

      
        
        Complex sum = num1.add(num2);
        System.out.println("Sum:");
        sum.display();

       
        Complex product = num1.multiply(num2);
        System.out.println("Product:");
        product.display();
    }


}

