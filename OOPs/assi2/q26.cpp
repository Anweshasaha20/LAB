#include <iostream>
#include <vector>
#include <string>
#include <ctime>  

using namespace std;

class GradeCard {
    string department;
    string studentName;
    string rollNumber;
    int semester;
    vector<string> subjects;
    vector<int> marks;
    float CGPA;

public:
    GradeCard(string dept, string name, string roll, int sem, vector<string> sub, vector<int> mark) 
        : department(dept), studentName(name), rollNumber(roll), semester(sem), subjects(sub), marks(mark) {
        calculateCGPA();
    }

    void calculateCGPA() {
        int totalMarks = 0;
        for (size_t i = 0; i < marks.size(); i++) {  
            totalMarks += marks[i];
        }
        CGPA = (float)totalMarks / (marks.size() * 10);  
    }

    float getCGPA() const {
        return CGPA;
    }

    string getStudentName() const {
        return studentName;
    }

    string getRollNumber() const {
        return rollNumber;
    }

    void display() const {
        cout << "Department: " << department << endl;
        cout << "Name: " << studentName << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Semester: " << semester << endl;
        cout << "Subjects and Marks: " << endl;
        for (size_t i = 0; i < subjects.size(); i++) {
            cout << subjects[i] << ": " << marks[i] << endl;
        }
        cout << "CGPA: " << CGPA << endl;
    }
};

int main() {
    srand(time(0));


    vector<string> subjects;
    subjects.push_back("Math");
    subjects.push_back("Physics");
    subjects.push_back("Chemistry");
    subjects.push_back("Computer Science");
    subjects.push_back("Electronics");

    vector<GradeCard> gradeCards;
    
    for (int i = 0; i < 60; i++) {

        vector<int> marks;
        marks.push_back(rand() % 101);
        marks.push_back(rand() % 101);
        marks.push_back(rand() % 101);
        marks.push_back(rand() % 101);
        marks.push_back(rand() % 101);
        
        gradeCards.push_back(GradeCard("IT", "Student " + to_string(i + 1), "Roll" + to_string(i + 1), 3, subjects, marks));
    }


    GradeCard* topStudent = &gradeCards[0];
    for (int i = 1; i < 60; i++) {
        if (gradeCards[i].getCGPA() > topStudent->getCGPA()) {
            topStudent = &gradeCards[i];
        }
    }

    cout << "Student with the highest CGPA:" << endl;
    cout << "Name: " << topStudent->getStudentName() << endl;
    cout << "Roll Number: " << topStudent->getRollNumber() << endl;
    cout << "CGPA: " << topStudent->getCGPA() << endl;

    return 0;
}
