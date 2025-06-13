#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        if (n & 1) count++;
        n >>= 1;
    }
    return count;
}
int main() {
    int n = 15;
    cout << "Number of set bits in " << n << ": " << countSetBits(n) << endl;
    return 0;
}