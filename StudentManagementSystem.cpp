#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    float marks;

    void inputStudent() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayStudent() {
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Marks: " << marks << endl;
    }
};

void saveStudentToFile(const Student& student) {
    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << student.name << " " << student.rollNo << " " << student.marks << endl;
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

void displayStudentsFromFile() {
    ifstream file("students.txt");
    if (file.is_open()) {
        string name;
        int rollNo;
        float marks;
        cout << "\n--- Student Records ---\n";
        while (file >> name >> rollNo >> marks) {
            cout << "Name: " << name << ", Roll No: " << rollNo << ", Marks: " << marks << endl;
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

void searchStudent(int rollNo) {
    ifstream file("students.txt");
    if (file.is_open()) {
        string name;
        int r;
        float marks;
        bool found = false;
        while (file >> name >> r >> marks) {
            if (r == rollNo) {
                cout << "\nStudent Found:\nName: " << name << ", Roll No: " << r << ", Marks: " << marks << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\nStudent with Roll No " << rollNo << " not found.\n";
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

int main() {
    vector<Student> students;
    int choice;
    do {
        cout << "\n1. Add Student\n2. View Students\n3. Search Student\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1: {
                Student s;
                s.inputStudent();
                saveStudentToFile(s);
                break;
            }
            case 2:
                displayStudentsFromFile();
                break;
            case 3: {
                int rollNo;
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                searchStudent(rollNo);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}