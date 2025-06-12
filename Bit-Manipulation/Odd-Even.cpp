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