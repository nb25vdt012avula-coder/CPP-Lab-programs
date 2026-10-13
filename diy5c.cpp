
#include <iostream>
using namespace std;

class Order {
private:
    static int nextID;
    int orderID;

public:
    Order() {
        orderID = nextID++;
    }

    void display() const {
        cout << "Order ID: " << orderID << endl;
    }
};

// Initialize static member
int Order::nextID = 1001;

int main() {
    Order o1, o2, o3, o4;

    o1.display();
    o2.display();
    o3.display();
    o4.display();

    return 0;
}
