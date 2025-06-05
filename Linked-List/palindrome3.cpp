#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    // Build palindrome from left half and length parity
    long long buildPalindrome(long long leftHalf, int length) {
        long long palindrome = leftHalf;
        if (length % 2 == 1) leftHalf /= 10; // skip middle digit for odd length

        // Append reverse of leftHalf to palindrome
        while (leftHalf > 0) {
            palindrome = palindrome * 10 + (leftHalf % 10);
            leftHalf /= 10;
        }
        return palindrome;
    }

    long long kthPalindromeWithDigits(int d, int k) {
        int halfLength = (d + 1) / 2;
        long long start = pow(10, halfLength - 1);  // smallest left half with halfLength digits
        long long count = 9 * pow(10, halfLength - 1);  // total palindromes with d digits

        if (k > count) return -1;  // k is out of range

        long long leftHalf = start + k - 1;  // find kth left half
        return buildPalindrome(leftHalf, d);
    }
};

int main() {
    Solution sol;

    int digits = 4;
    cout << "Palindromes with " << digits << " digits:" << endl;

    // Print first 10 palindromes with 3 digits
    for (int k = 1; k <= 10; k++) {
        long long p = sol.kthPalindromeWithDigits(digits, k);
        cout << k << "th palindrome = " << p << endl;
    }

    return 0;
}
