#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Define modPow here, at top level (outside main)
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Define countGoodStrings here too (optional)
int countGoodStrings(long long n) {
    long long evenCount = (n + 1) / 2;
    long long oddCount = n / 2;

    long long evenPow = modPow(5, evenCount, MOD);
    long long oddPow = modPow(4, oddCount, MOD);

    return (evenPow * oddPow) % MOD;
}

int main() {
    long long n;
    cout<<"Enter the value of n: ";
    cin >> n;
    cout << "The number of good strings of length " << n << " is: ";
    cout << countGoodStrings(n) << "\n";
    return 0;
}
