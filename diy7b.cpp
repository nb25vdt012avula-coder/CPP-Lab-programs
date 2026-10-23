#include <iostream>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape() {
        color = "Blue";
        cout << "Shape constructor called" << endl;
    }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon() {
        sides = 4;
        cout << "Polygon constructor called" << endl;
    }
};

class Rectangle : public Polygon {
    double length;

public:
    Rectangle(double l) {
        length = l;
        cout << "Rectangle constructor called" << endl;
    }

    void display() {
        cout << "\nShape Details:\n";
        cout << "Color: " << color << endl;
        cout << "Number of sides: " << sides << endl;
        cout << "Length: " << length << endl;
    }
};

int main() {
    Rectangle r(10.5);
    r.display();

    return 0;
}