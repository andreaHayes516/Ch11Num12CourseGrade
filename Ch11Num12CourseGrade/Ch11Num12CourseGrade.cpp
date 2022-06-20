/************************************************
** Author: Andrea Hayes
** Date: June 7,2020
** Purpose: Figure Grades
** Input: Student Name, ID and test scores
** Processing: Average and Grade
** Output: Student's Name, ID num, Avg test score and grade
*************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Declare Structure
struct Student
{
    Student() {};
    string name;
    int id{};
    double* test{};
    double avg{};
    char grade{};
};
int main() {
    
    // Declare variables
    int numTest, numStud;

    // Get User Input
    cout << "How many students? ";
    cin >> numStud;
    cout << "How many test scores? ";
    cin >> numTest;
    // Dynamically Alocate Memory
    Student* stud = nullptr;
    stud = new Student[numStud];
    // More User Input
    for (int i = 0; i < numStud; i++) {
        string nothing;
        getline(cin, nothing);
        cout << endl;
        cout << "Student name: ";
        getline(cin, stud[i].name);
        cout << "Student ID Number: ";
        cin >> stud[i].id;

        // Allocate Memory for Test, Get Scores and figure average and grade
        stud[i].test = new double[numTest];
        double scores = 0;
        for (int j = 0; j < numTest; j++) {
            stud[i].test[j] = -1;
            while (stud[i].test[j] < 0) {
                cout << "Enter a score: ";
                cin >> stud[i].test[j];
                scores += stud[i].test[j];
            }
            stud[i].avg = scores / numTest;

            if (stud[i].avg >= 91) {
                stud[i].grade = 'A';
            }
            else if (stud[i].avg >= 81) {
                stud[i].grade = 'B';
            }
            else if (stud[i].avg >= 71) {
                stud[i].grade = 'C';
            }
            else if (stud[i].avg >= 61) {
                stud[i].grade = 'D';
            }
            else {
                stud[i].grade = 'F';
            }
        }

    }
    // Display Results
    cout << endl;
    for (int i = 0; i < numStud; i++) {
        cout << "Name:" << stud[i].name << endl;
        cout << "ID Number: " << stud[i].id << endl;
        cout << "Average Score: " << stud[i].avg << endl;
        cout << "Grade: " << stud[i].grade << endl;
        cout << endl;
    }

}