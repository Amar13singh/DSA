#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    void reverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

    string reverseWords(string s) {
        // Step 1: Trim spaces (in-place)
        int n = s.length();
        int i = 0, j = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        bool spaceSeen = false;
        while (i < n) {
            if (s[i] != ' ') {
                s[j++] = s[i++];
                spaceSeen = false;
            } else if (!spaceSeen) {
                s[j++] = ' ';
                spaceSeen = true;
                i++;
            } else {
                i++;
            }
        }

        // Remove trailing space
        if (j > 0 && s[j - 1] == ' ') j--;

        s.resize(j);

        // Step 2: Reverse the whole string
        reverse(s, 0, s.size() - 1);

        // Step 3: Reverse each word
        int start = 0;
        for (int end = 0; end <= s.length(); ++end) {
            if (end == s.length() || s[end] == ' ') {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }

        return s;
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    string output = sol.reverseWords(input);
    cout << "Reversed: \"" << output << "\"" << endl;
    return 0;
}

