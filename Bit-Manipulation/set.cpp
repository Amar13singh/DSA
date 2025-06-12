#include <iostream>
using namespace std;

bool isithBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}
int main() {
    int n = 10; // 1010 in binary
    int i = 2;
    cout << "Is the " << i << "th bit set in " << n << "? " << (isithBitSet(n, i) ? "Yes" : "No") << endl;
    return 0;
}