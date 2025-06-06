#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    long long buildPalindrome(long long leftHalf, int length) {
        long long palindrome = leftHalf;
        if (length % 2 == 1) leftHalf /= 10;

        while (leftHalf > 0) {
            palindrome = palindrome * 10 + (leftHalf % 10);
            leftHalf /= 10;
        }
        return palindrome;
    }

    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;

        int halfLength = (intLength + 1) / 2;
        long long start = pow(10, halfLength - 1);
        long long count = 9 * start;

        for (int k : queries) {
            if (k > count) {
                ans.push_back(-1);
            } else {
                long long leftHalf = start + k - 1;
                ans.push_back(buildPalindrome(leftHalf, intLength));
            }
        }

        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> queries = {1, 2, 3, 4, 5};
    int intLength = 5;
    vector<long long> result = sol.kthPalindrome(queries, intLength);
    for (long long num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}