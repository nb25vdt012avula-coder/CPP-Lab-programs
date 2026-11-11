#include <iostream>
#include <thread>
#include <mutex>

long counter = 0;
std::mutex mtx;

void addSafe(int times) {
    for (int i = 0; i < times; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
}

int main() {
    std::thread t1(addSafe, 100000);
    std::thread t2(addSafe, 100000);

    t1.join();
    t2.join();

    std::cout << "Synchronized counter = "
              << counter << " (expected 200000)\n";

    return 0;
}
