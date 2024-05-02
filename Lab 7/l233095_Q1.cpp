#include <iostream>
#include <string>

using namespace std;

const int MAX_SUBJECTS = 10;
const int MAX_COURSES = 10;

class Subject {
private:
    string subjectName;
    string teacherName;

public:
    Subject() : subjectName(""), teacherName("") {}

    void setSubjectName(const string& name) {
        subjectName = name;
    }

    void setTeacherName(const string& name) {
        teacherName = name;
    }

    string getSubjectName() const {
        return subjectName;
    }

    string getTeacherName() const {
        return teacherName;
    }
};

class Teacher {
private:
    string teacherName;
    Subject subjects[MAX_SUBJECTS];
    int numSubjects;

public:
    Teacher() : teacherName(""), numSubjects(0) {}

    void setTeacherName(const string& name) {
        teacherName = name;
    }

    string getTeacherName() const {
        return teacherName;
    }

    bool addSubject(const Subject& subject) {
        if (numSubjects < MAX_SUBJECTS) {
            subjects[numSubjects++] = subject;
            return true;
        }
        return false;
    }

    void displaySubjects() const {
        for (int i = 0; i < numSubjects; i++) {
            cout << "Subject: " << subjects[i].getSubjectName() << ", Taught by: " << subjects[i].getTeacherName() << endl;
        }
    }
};

class Course {
private:
    string courseName;
    string courseCode;
    string teacherName;

public:
    Course() : courseName(""), courseCode(""), teacherName("") {}

    void setCourseName(const string& name) {
        courseName = name;
    }

    void setCourseCode(const string& code) {
        courseCode = code;
    }

    void setTeacherName(const string& name) {
        teacherName = name;
    }

    string getCourseName() const {
        return courseName;
    }

    string getCourseCode() const {
        return courseCode;
    }

    string getTeacherName() const {
        return teacherName;
    }
};

class Student {
private:
    string studentName;
    int rollNumber;
    Course courses[MAX_COURSES];
    int numCourses;

public:
    Student() : studentName(""), rollNumber(0), numCourses(0) {}

    void setStudentName(const string& name) {
        studentName = name;
    }

    void setRollNumber(int roll) {
        rollNumber = roll;
    }

    bool addCourse(const Course& course) {
        if (numCourses < MAX_COURSES) {
            courses[numCourses++] = course;
            return true;
        }
        return false;
    }

    void displayCourses() const {
        for (int i = 0; i < numCourses; i++) {
            cout << "Course: " << courses[i].getCourseName() << ", Code: " << courses[i].getCourseCode()
                 << ", Teacher: " << courses[i].getTeacherName() << endl;
        }
    }
};

int main() {
    


    Teacher t1;
    t1.setTeacherName("Mr. slahaudin");
    
    Subject s1;
    s1.setSubjectName("OOP");
    s1.setTeacherName(t1.getTeacherName());
    t1.addSubject(s1);

    Student st1;
    st1.setStudentName("Hassan");
    st1.setRollNumber(101);

    Course c1;
    c1.setCourseName("MULTIVERIABLE");
    c1.setCourseCode("MATH234");
    c1.setTeacherName("Mr. Afzal khan");
    st1.addCourse(c1);

    cout << "Teacher and Subjects: " << endl;
    t1.displaySubjects();

    cout << "Student and Courses: " << endl;
    st1.displayCourses();

    return 0;
}
