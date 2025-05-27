#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;  // Skip leading spaces

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Check overflow
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;

            i++;
        }

        return static_cast<int>(sign * result);
    }
};


int main() {
    Solution sol;
    string input = "   -42";
    int result = sol.myAtoi(input);
    cout << "Result: " << result << endl;
    return 0;
}