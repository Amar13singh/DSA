#include <iostream>
using namespace std;

void generateBinary(int n, string current) {
    if (n == 0) {
        cout << current <<" ";
        return;
    }
    generateBinary(n - 1, current + '0');
    generateBinary(n - 1, current + '1');
}

int main() {
    int n = 3; // change this value to generate strings of different lengths
    generateBinary(n, "");
    return 0;
}

// Time Complexity: O(2^n)
// Space Complexity: O(n)
