#include <bits/stdc++.h>
using namespace std;

void printPrimeFactors(int n) {
    // Handle 2 separately
    while ((n & 1) == 0) {  // same as n % 2 == 0
        cout << 2 << " ";
        n >>= 1;  // same as n /= 2
    }

    // Check only odd numbers from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // If a prime factor greater than sqrt(n) remains
    if (n > 1)
        cout << n << " ";
}
 int main() {
    int n = 315;
    cout << "Prime factors of " << n << ": ";
    printPrimeFactors(n);
    cout << endl;
    return 0;
}