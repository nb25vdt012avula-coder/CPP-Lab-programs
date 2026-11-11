#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6};

    // 1. Product of all elements (initial value = 1)
    long long product = accumulate(numbers.begin(), numbers.end(), 1LL,
        [](long long acc, int x) {
            return acc * x;
        }
    );

    // 2. Sum of only even numbers (initial value = 0)
    int evenSum = accumulate(numbers.begin(), numbers.end(), 0,
        [](int sum, int x) {
            return (x % 2 == 0) ? (sum + x) : sum;
        }
    );

    cout << "Original numbers: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    cout << "Product of all elements: " << product << endl;
    cout << "Sum of only even elements: " << evenSum << endl;

    return 0;
}