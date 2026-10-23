#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(string message) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(string message) override {
        cout << "Console: " << message << endl;
    }
};

class FileLogger : public Logger {
public:
    void write(string message) override {
        ofstream file("log.txt", ios::app);

        if (file.is_open()) {
            file << message << endl;
            file.close();
            cout << "Message written to file." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

int main() {
    ConsoleLogger console;
    FileLogger file;

    Logger* logger;
    int choice;

    cout << "1. Console Logger\n";
    cout << "2. File Logger\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    string message;
    cout << "Enter message: ";
    getline(cin, message);

    if (choice == 1) {
        logger = &console;
    } else if (choice == 2) {
        logger = &file;
    } else {
        cout << "Invalid choice." << endl;
        return 0;
    }

    logger->write(message);

    return 0;
}