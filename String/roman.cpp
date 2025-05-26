#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int val[26] = {};  // A-Z
        val['I' - 'A'] = 1;
        val['V' - 'A'] = 5;
        val['X' - 'A'] = 10;
        val['L' - 'A'] = 50;
        val['C' - 'A'] = 100;
        val['D' - 'A'] = 500;
        val['M' - 'A'] = 1000;

        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            int curr = val[s[i] - 'A'];
            int next = (i + 1 < s.size()) ? val[s[i + 1] - 'A'] : 0;
            result += (curr < next) ? -curr : curr;
        }

        return result;
    }
};


 int main() {
    Solution sol;
    string roman = "MCMXCIV";
    int result = sol.romanToInt(roman);
    cout << "Integer: " << result << endl;
    return 0;
}