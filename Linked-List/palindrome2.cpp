#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    // Generate palindrome from left half (string) and length
    long long createPalindrome(long long left, bool oddLength) {
        long long palin = left;
        if (oddLength) left /= 10;  // skip middle digit for odd length

        // Append reverse of left to palin
        while (left > 0) {
            palin = palin * 10 + (left % 10);
            left /= 10;
        }
        return palin;
    }

    long long nthPalindrome(int n) {
        if (n <= 9) return n;  // single-digit palindromes

        n -= 9;  // subtract single-digit palindromes count
        int length = 2;  // start from length 2

        while (true) {
            int halfLen = (length + 1) / 2;
            int countHalf = (int)pow(10, halfLen - 1) * 9;  // number of palindromes with this length

            if (n <= countHalf) {
                long long start = (long long)pow(10, halfLen - 1);
                long long leftHalf = start + n - 1;
                return createPalindrome(leftHalf, length % 2 != 0);
            }
            else {
                n -= countHalf;
                length++;
            }
        }
    }
};

int main() {
    Solution sol;
    for (int i = 1; i <= 20; i++) {
        cout << i << "th palindrome = " << sol.nthPalindrome(i) << endl;
    }
    return 0;
}
