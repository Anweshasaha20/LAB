class Student {
    private String name;
    private double mark1, mark2, mark3;

    public void setDetails(String name, double mark1, double mark2, double mark3) {
        this.name = name;
        this.mark1 = mark1;
        this.mark2 = mark2;
        this.mark3 = mark3;
    }

    public double computeTotal() {
        return mark1 + mark2 + mark3;
    }

    public double computeAverage() {
        return computeTotal() / 3;
    }

    public void display() {
        System.out.println("Student Name: " + name);
        System.out.println("Total Marks: " + computeTotal());
    }
}

 class Main {
    public static void main(String[] args) {
        Student student1 = new Student();
        student1.setDetails("Alice", 85, 90, 78);
        student1.display();
    }
}

