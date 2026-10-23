#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) {
        name = n;
        id = i;
    }

    void displayEmployee() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Manager : public Employee {
    int teamSize;

public:
    Manager(string n, int i, int t) : Employee(n, i) {
        teamSize = t;
    }

    void display() {
        cout << "\nManager Details:\n";
        displayEmployee();
        cout << "Team Size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
    string skill;

public:
    Engineer(string n, int i, string s) : Employee(n, i) {
        skill = s;
    }

    void display() {
        cout << "\nEngineer Details:\n";
        displayEmployee();
        cout << "Skill: " << skill << endl;
    }
};

int main() {
    Manager m("Rahul", 101, 8);
    Engineer e("Arun", 102, "C++");

    m.display();
    e.display();

    return 0;
}