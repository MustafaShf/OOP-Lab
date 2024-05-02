#include <iostream>
using namespace std;

class Student {
public:
    string studentName;
    int id;

    // Constructor
    Student(string name = "", int id = 0) : studentName(name), id(id) {}
};

void deleteStudent(Student*& stdData, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        return;
    }
    
    // Shift elements left to fill the gap
    for (int i = index; i < size - 1; i++) {
        stdData[i] = stdData[i + 1];
    }

    // Decrease the size by 1
    size--;

    // Create a new array of the updated size
    Student* temp = new Student[size];

    // Copy the elements to the new array
    for (int i = 0; i < size; i++) {
        temp[i] = stdData[i];
    }

    // Delete the old array and update the pointer
    delete[] stdData;
    stdData = temp;
}

int main() {
    int size = 5;
    Student* stdData = new Student[size];

    // Example initialization
    for (int i = 0; i < size; i++) {
        stdData[i] = Student("Student" + to_string(i + 1), i + 1);
    }

    // Delete the second object (index 1)
    deleteStudent(stdData, size, 1);

    // Print to verify
    for (int i = 0; i < size; i++) {
        cout << "Student Name: " << stdData[i].studentName << ", ID: " << stdData[i].id << endl;
    }

    // Clean up
    delete[] stdData;
}
