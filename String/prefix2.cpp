#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isCommonPrefix(vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].substr(0, len) != prefix) return false;
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int minLen = strs[0].size();
        for (const string& s : strs) {
            minLen = min(minLen, (int)s.size());
        }

        int low = 1, high = minLen, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return strs[0].substr(0, ans);
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}