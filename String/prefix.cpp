#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Take the first string as reference
        for (int i = 0; i < strs[0].size(); ++i) {
            char ch = strs[0][i];

            // Compare this character with all other strings at position i
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return strs[0].substr(0, i);  // return prefix till now
                }
            }
        }

        return strs[0];  // whole string is common prefix
    }
};


int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    Solution sol;
    string result = sol.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}