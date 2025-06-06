#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minChar(n);
        minChar[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minChar[i] = min(s[i], minChar[i + 1]);
        }

        string result;
        stack<char> t;
        int i = 0;

        while (i < n) {
            // Push the current char from s to t
            t.push(s[i]);
            
            // Try to pop from t while top is <= smallest char remaining in s
            while (!t.empty() && (i == n - 1 || t.top() <= minChar[i + 1])) {
                result.push_back(t.top());
                t.pop();
            }
            i++;
        }

        // Pop any remaining chars from t
        while (!t.empty()) {
            result.push_back(t.top());
            t.pop();
        }

        return result;
    }
};

int main(){
    Solution sol;
    string s = "zza";
    cout<<"The lexicographically smallest string is: ";
    cout << sol.robotWithString(s) << endl;
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)
