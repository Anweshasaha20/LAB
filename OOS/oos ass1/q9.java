import java.util.ArrayList;
import java.util.List;


class Person {
    private int age;
    private double weight;
    private double height;
    private String dateOfBirth;
    private String address;

  
    public Person(int age, double weight, double height, String dateOfBirth, String address) {
        this.age = age;
        this.weight = weight;
        this.height = height;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
    }

  
    public int getAge() {
        return age;
    }

    public double getWeight() {
        return weight;
    }

    public double getHeight() {
        return height;
    }

    public String getDateOfBirth() {
        return dateOfBirth;
    }

    public String getAddress() {
        return address;
    }

    
    public void setAge(int age) {
        this.age = age;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public void setDateOfBirth(String dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public void setAddress(String address) {
        this.address = address;
    }
}


class Employee extends Person {
    private double salary;
    private String dateOfJoining;
    private int experience;

  
    public Employee(int age, double weight, double height, String dateOfBirth, String address,
                    double salary, String dateOfJoining, int experience) {
        super(age, weight, height, dateOfBirth, address);
        this.salary = salary;
        this.dateOfJoining = dateOfJoining;
        this.experience = experience;
    }

   
    public double getSalary() {
        return salary;
    }

    public String getDateOfJoining() {
        return dateOfJoining;
    }

    public int getExperience() {
        return experience;
    }

  
    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void setDateOfJoining(String dateOfJoining) {
        this.dateOfJoining = dateOfJoining;
    }

    public void setExperience(int experience) {
        this.experience = experience;
    }
}


class Student extends Person {
    private int roll;
    private List<String> listOfSubjects;
    private List<Double> marks;

    
    public Student(int age, double weight, double height, String dateOfBirth, String address,
                   int roll, List<String> listOfSubjects, List<Double> marks) {
        super(age, weight, height, dateOfBirth, address);
        this.roll = roll;
        this.listOfSubjects = listOfSubjects;
        this.marks = marks;
    }

  
    public int getRoll() {
        return roll;
    }

    public List<String> getListOfSubjects() {
        return listOfSubjects;
    }

    public List<Double> getMarks() {
        return marks;
    }


    public void setRoll(int roll) {
        this.roll = roll;
    }

    public void setListOfSubjects(List<String> listOfSubjects) {
        this.listOfSubjects = listOfSubjects;
    }

    public void setMarks(List<Double> marks) {
        this.marks = marks;
    }


    public char calculateGrade() {
        if (marks.isEmpty()) return 'F'; 
    
        double sum = 0.0;
        for (double mark : marks) {
            sum += mark;
        }
        double avg = sum / marks.size();
    
        if (avg >= 90) return 'A';
        else if (avg >= 80) return 'B';
        else if (avg >= 70) return 'C';
        else if (avg >= 60) return 'D';
        else return 'F';
    }
}


class Technician extends Employee {
   
    public Technician(int age, double weight, double height, String dateOfBirth, String address,
                      double salary, String dateOfJoining, int experience) {
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
    }
}


class Professor extends Employee {
    private List<String> courses;
    private List<String> listOfAdvisee;

   
    public Professor(int age, double weight, double height, String dateOfBirth, String address,
                     double salary, String dateOfJoining, int experience, List<String> courses, List<String> listOfAdvisee) {
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
        this.courses = courses;
        this.listOfAdvisee = listOfAdvisee;
    }

  
    public void addCourse(String course) {
        courses.add(course);
    }

    public void removeCourse(String course) {
        courses.remove(course);
    }

   
    public void addAdvisee(String advisee) {
        listOfAdvisee.add(advisee);
    }

    public void removeAdvisee(String advisee) {
        listOfAdvisee.remove(advisee);
    }


    public List<String> getCourses() {
        return courses;
    }

    public List<String> getListOfAdvisee() {
        return listOfAdvisee;
    }
}


 class Main {
    public static void main(String[] args) {
      
        List<String> subjects = List.of("Math", "Science", "History");
        List<Double> marks = List.of(95.0, 85.0, 75.0);
        Student student = new Student(20, 65.5, 170.0, "2003-05-15", "123 Main St", 101, subjects, marks);
        System.out.println("Student Grade: " + student.calculateGrade());

        
        Technician technician = new Technician(30, 70.0, 175.0, "1993-08-25", "456 Tech St", 50000.0, "2015-06-01", 8);
        System.out.println("Technician Experience: " + technician.getExperience() + " years");

        
        List<String> courses = new ArrayList<>(List.of("Algorithms", "Data Structures"));
        List<String> advisees = new ArrayList<>(List.of("Alice", "Bob"));
        Professor professor = new Professor(45, 80.0, 180.0, "1978-12-10", "789 University Ave", 80000.0, "2005-09-01", 18, courses, advisees);
        professor.addCourse("Machine Learning");
        professor.addAdvisee("Charlie");
        System.out.println("Professor Courses: " + professor.getCourses());
        System.out.println("Professor Advisees: " + professor.getListOfAdvisee());
    }
}