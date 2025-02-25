
class Student {
    private String name;
    private int rollNo;
    private String[] subjects;

    public Student(String name, int rollNo, String[] subjects) {
        this.name = name;
        this.rollNo = rollNo;
        this.subjects = subjects;
    }

    public String getName() {
        return name;
    }

    public int getRollNo() {
        return rollNo;
    }

    public String[] getSubjects() {
        return subjects;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setRollNo(int rollNo) {
        this.rollNo = rollNo;
    }

    public void setSubjects(String[] subjects) {
        this.subjects = subjects;
    }
}

class TabulationSheet {
    private String subject;
    private int[] rollNos;
    private int[] marks;
    private int count;

    public TabulationSheet(String subject, int maxStudents) {
        this.subject = subject;
        this.rollNos = new int[maxStudents];
        this.marks = new int[maxStudents];
        this.count = 0;
    }

    public void addMarks(int rollNo, int marks) {
        rollNos[count] = rollNo;
        this.marks[count] = marks;
        count++;
    }

    public int getMarks(int rollNo) {
        for (int i = 0; i < count; i++) {
            if (rollNos[i] == rollNo) {
                return marks[i];
            }
        }
        return -1; // Marks not found
    }

    public String getSubject() {
        return subject;
    }
}

class MarkSheet {
    private Student student;
    private int[] marks;

    public MarkSheet(Student student, int numSubjects) {
        this.student = student;
        this.marks = new int[numSubjects];
    }

    public void addMarks(int subjectIndex, int marks) {
        this.marks[subjectIndex] = marks;
    }

    public void printMarkSheet() {
        System.out.println("Mark Sheet for " + student.getName() + " (Roll No: " + student.getRollNo() + ")");
        String[] subjects = student.getSubjects();
        for (int i = 0; i < subjects.length; i++) {
            System.out.println(subjects[i] + ": " + (marks[i] != -1 ? marks[i] : "N/A"));
        }
        System.out.println();
    }
}

 class Main {
    public static void main(String[] args) {
        String[] subjects = {"Math", "Science", "English", "History", "Geography"};

        Student student1 = new Student("Alice", 101, subjects);
        Student student2 = new Student("Bob", 102, subjects);
        Student student3 = new Student("Charlie", 103, subjects);

        TabulationSheet mathSheet = new TabulationSheet("Math", 10);
        TabulationSheet scienceSheet = new TabulationSheet("Science", 10);
        TabulationSheet englishSheet = new TabulationSheet("English", 10);
        TabulationSheet historySheet = new TabulationSheet("History", 10);
        TabulationSheet geographySheet = new TabulationSheet("Geography", 10);

        mathSheet.addMarks(101, 90);
        mathSheet.addMarks(102, 85);
        mathSheet.addMarks(103, 78);

        scienceSheet.addMarks(101, 88);
        scienceSheet.addMarks(102, 92);
        scienceSheet.addMarks(103, 80);

        englishSheet.addMarks(101, 75);
        englishSheet.addMarks(102, 80);
        englishSheet.addMarks(103, 85);

        historySheet.addMarks(101, 82);
        historySheet.addMarks(102, 78);
        historySheet.addMarks(103, 90);

        geographySheet.addMarks(101, 95);
        geographySheet.addMarks(102, 88);
        geographySheet.addMarks(103, 84);

        MarkSheet markSheet1 = new MarkSheet(student1, subjects.length);
        markSheet1.addMarks(0, mathSheet.getMarks(101));
        markSheet1.addMarks(1, scienceSheet.getMarks(101));
        markSheet1.addMarks(2, englishSheet.getMarks(101));
        markSheet1.addMarks(3, historySheet.getMarks(101));
        markSheet1.addMarks(4, geographySheet.getMarks(101));

        MarkSheet markSheet2 = new MarkSheet(student2, subjects.length);
        markSheet2.addMarks(0, mathSheet.getMarks(102));
        markSheet2.addMarks(1, scienceSheet.getMarks(102));
        markSheet2.addMarks(2, englishSheet.getMarks(102));
        markSheet2.addMarks(3, historySheet.getMarks(102));
        markSheet2.addMarks(4, geographySheet.getMarks(102));

        MarkSheet markSheet3 = new MarkSheet(student3, subjects.length);
        markSheet3.addMarks(0, mathSheet.getMarks(103));
        markSheet3.addMarks(1, scienceSheet.getMarks(103));
        markSheet3.addMarks(2, englishSheet.getMarks(103));
        markSheet3.addMarks(3, historySheet.getMarks(103));
        markSheet3.addMarks(4, geographySheet.getMarks(103));

        markSheet1.printMarkSheet();
        markSheet2.printMarkSheet();
        markSheet3.printMarkSheet();
    }
}