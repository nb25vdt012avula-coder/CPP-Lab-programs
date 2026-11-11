#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements (N): ";
    if (!(cin >> n) || n <= 0) return 0;

    priority_queue<int> pq; // Max-heap by default

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pq.push(val);
    }

    cout << "\nTop 3 largest numbers: ";
    for (int k = 0; k < 3 && !pq.empty(); ++k) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}