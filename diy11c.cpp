#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> freq;
    string line, word;

    cout << "Enter a line of text: ";
    getline(cin, line);

    stringstream ss(line);
    while (ss >> word) {
        freq[word]++;
    }

    cout << "\nWord frequencies:" << endl;
    string mostFreqWord = "";
    int maxCount = 0;

    for (const auto& pair : freq) {
        cout << pair.first << ": " << pair.second << endl;
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFreqWord = pair.first;
        }
    }

    if (!freq.empty()) {
        cout << "\nMost frequent word: \"" << mostFreqWord 
             << "\" (count: " << maxCount << ")" << endl;
    } else {
        cout << "\nNo words entered." << endl;
    }

    return 0;
}