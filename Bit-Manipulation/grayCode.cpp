#include <bits/stdc++.h>
using namespace std;


void printGrayBinary(int n) {
    int total = 1 << n;
    for (int i = 0; i < total; ++i) {
        int gray = i ^ (i >> 1);
        bitset<8> b(gray);  // adjust size as needed
        cout << b.to_string().substr(8 - n) << endl;
    }
}
int main() {
    int n = 3;
    printGrayBinary(n);
    return 0;
}