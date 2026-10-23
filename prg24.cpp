
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() const = 0;

    virtual ~Animal() {
        cout << "~Animal\n";
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof\n";
    }

    ~Dog() {
        cout << "~Dog\n";
    }
};

int main() {
    // Upcasting: Derived pointer to Base pointer
    Animal *a = new Dog();

    // Safe downcasting using dynamic_cast
    if (Dog *d = dynamic_cast<Dog*>(a)) {
        cout << "downcast ok-> ";
        d->speak();
    }

    // Delete through base-class pointer
    delete a;

    return 0;
}
