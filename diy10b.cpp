
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");

    if (!in || !out) {
        cout << "File opening failed!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(in, line)) {
        out << lineNumber << ". " << line << endl;
        lineNumber++;
    }

    cout << "File copied successfully with line numbers." << endl;

    in.close();
    out.close();

    return 0;
}
