#include <iostream>
using namespace std;

int minBitFlips(int a, int b) {
    int xorResult = a ^ b;
    int count = 0;
    while (xorResult) {
        xorResult &= (xorResult - 1);  // Brian Kernighan's Trick
        count++;
    }
    return count;
}
int main() {
    int a = 10, b = 7;
    cout << "Minimum bit flips required: " << minBitFlips(a, b) << endl;
    return 0;
}   