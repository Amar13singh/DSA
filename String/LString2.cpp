#include<iostream>
#include <string>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        string res;
        for (int i = 0; i < n; i++) {
            res = max(res, word.substr(i, min(n - numFriends + 1, n - i)));
        }
        return res;
    }
};

int main() {
    Solution solution;
    string word = "ababbb";
    int numFriends = 2;
    string result = solution.answerString(word, numFriends);
    cout << "Result: " << result << endl;
    return 0;
}