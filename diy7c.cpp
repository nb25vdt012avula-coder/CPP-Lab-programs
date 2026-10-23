#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNo;

public:
    Student(string n, int r) : Person(n) {
        rollNo = r;
    }
};

class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(string n, int e) : Person(n) {
        empId = e;
    }
};

class TA : public Student, public Employee {
    string subject;

public:
    TA(string n, int r, int e, string s)
        : Person(n), Student(n, r),
          Employee(n, e) {
        subject = s;
    }

    void display() {
        cout << "Teaching Assistant Details:\n";
        displayPerson();
        cout << "Roll Number: " << rollNo << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    TA t("Bhanu", 25, 501, "Mathematics");
    t.display();

    return 0;
}