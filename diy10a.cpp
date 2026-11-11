
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("nums.txt");

    if (!in) {
        cout << "File opening failed!" << endl;
        return 1;
    }

    int num, count = 0, sum = 0;
    int min, max;

    while (in >> num) {
        if (count == 0) {
            min = max = num;
        }

        if (num < min)
            min = num;

        if (num > max)
            max = num;

        sum += num;
        count++;
    }

    if (count > 0) {
        cout << "Count = " << count << endl;
        cout << "Sum = " << sum << endl;
        cout << "Minimum = " << min << endl;
        cout << "Maximum = " << max << endl;
    }
    else {
        cout << "No numbers found in file." << endl;
    }

    in.close();

    return 0;
}
