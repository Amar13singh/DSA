#include <iostream>
#include <vector>
using namespace std;

void backtrack(int open, int close, int n, string current, vector<string>& result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        backtrack(open + 1, close, n, current + '(', result);
    }
    if (close < open) {
        backtrack(open, close + 1, n, current + ')', result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(0, 0, n, "", result);
    return result;
}

int main() {
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for (const string& s : ans) {
        cout << s << endl;
    }
    return 0;
}
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
