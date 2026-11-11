
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Student class
class Student {
public:
    string name;
    int marks;
};

int main() {

    // Write student records into file
    ofstream out("students.txt");

    out << "Asha 91\n";
    out << "Ravi 78\n";
    out << "Meera 88\n";

    out.close();

    // Read records into Student objects
    ifstream in("students.txt");

    if (!in) {
        cout << "File opening failed!" << endl;
        return 1;
    }

    Student s[100];
    int count = 0;

    while (count < 100 &&
           in >> s[count].name >> s[count].marks) {
        count++;
    }

    in.close();

    // Find topper
    if (count > 0) {
        int highest = 0;

        for (int i = 1; i < count; i++) {
            if (s[i].marks > s[highest].marks) {
                highest = i;
            }
        }

        cout << "Topper Details:" << endl;
        cout << "Name: " << s[highest].name << endl;
        cout << "Marks: " << s[highest].marks << endl;
    }
    else {
        cout << "No student records found." << endl;
    }

    return 0;
}
