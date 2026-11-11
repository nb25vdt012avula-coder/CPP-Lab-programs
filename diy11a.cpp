#include <iostream>
using namespace std;

// Template function to swap two values
template <typename T>
void swapVals(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template function to find the maximum element in an array
template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    // Testing swapVals with int and double
    int a = 10, b = 20;
    cout << "Before swap (int): a = " << a << ", b = " << b << endl;
    swapVals(a, b);
    cout << "After swap (int):  a = " << a << ", b = " << b << endl;

    double x = 3.14, y = 9.81;
    cout << "\nBefore swap (double): x = " << x << ", y = " << y << endl;
    swapVals(x, y);
    cout << "After swap (double):  x = " << x << ", y = " << y << endl;

    // Testing findMax with int and double arrays
    int intArr[] = {15, 42, 8, 99, 23};
    int nInt = sizeof(intArr) / sizeof(intArr[0]);
    cout << "\nMax in int array: " << findMax(intArr, nInt) << endl;

    double dblArr[] = {2.5, 18.7, 9.1, 4.3};
    int nDbl = sizeof(dblArr) / sizeof(dblArr[0]);
    cout << "Max in double array: " << findMax(dblArr, nDbl) << endl;

    return 0;
}