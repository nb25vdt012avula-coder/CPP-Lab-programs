#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> items = {
        {"Router", 150},
        {"Switch", 80},
        {"Hub", 45},
        {"Modem", 120}
    };

    // Sort ascending by the integer (second) field
    sort(items.begin(), items.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });

    cout << "Sorted pairs by second field (ascending):" << endl;
    for (const auto& p : items) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}