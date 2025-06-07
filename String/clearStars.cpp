#include <bits/stdc++.h>
using namespace std;


    string clearStars(string s) {
        vector<stack<int>> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                cnt[s[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (!cnt[j].empty()) {
                        s[cnt[j].top()] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }

int main() {
    string s = "leet**cod*e";
    cout << "Input: " << s << endl;
    string result = clearStars(s);
    cout << "Output: " << result << endl;
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)