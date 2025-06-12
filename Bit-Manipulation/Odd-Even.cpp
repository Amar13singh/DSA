#include <iostream>
using namespace std;

bool isOdd(int n) {
    return (n & 1);
}
int main() {
    int n = 5;
    cout << "Is " << n << " odd? " << (isOdd(n) ? "Yes" : "No") << endl;
    return 0;
}


// Key Concept:
// In binary, the least significant bit (LSB) determines if a number is odd or even:

// If LSB is 1 → Number is odd

// If LSB is 0 → Number is even

