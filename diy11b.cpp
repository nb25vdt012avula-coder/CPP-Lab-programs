#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    vector<T> elements;

public:
    void enqueue(const T& item) {
        elements.push_back(item);
    }

    void dequeue() {
        if (elements.empty()) {
            throw runtime_error("Queue is empty, cannot dequeue.");
        }
        elements.erase(elements.begin());
    }

    T front() const {
        if (elements.empty()) {
            throw runtime_error("Queue is empty, no front element.");
        }
        return elements.front();
    }

    bool empty() const {
        return elements.empty();
    }
};

int main() {
    Queue<string> strQueue;

    // Enqueue strings
    strQueue.enqueue("Alpha");
    strQueue.enqueue("Beta");
    strQueue.enqueue("Gamma");

    cout << "Current front: " << strQueue.front() << endl; // Alpha

    strQueue.dequeue();
    cout << "Front after 1 dequeue: " << strQueue.front() << endl; // Beta

    strQueue.dequeue();
    cout << "Front after 2 dequeues: " << strQueue.front() << endl; // Gamma

    strQueue.dequeue();
    cout << "Queue is empty: " << (strQueue.empty() ? "Yes" : "No") << endl;

    return 0;
}