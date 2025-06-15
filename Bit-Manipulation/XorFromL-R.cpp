#include<bits/stdc++.h>
using namespace std;

int xorFrom0ToN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int xorRange(int L, int R) {
    return xorFrom0ToN(R) ^ xorFrom0ToN(L - 1);
}
int main() {
    int L = 3, R = 8;
    int result = xorRange(L, R);
    cout << "XOR from " << L << " to " << R << " is: " << result << endl;
    return 0;
}