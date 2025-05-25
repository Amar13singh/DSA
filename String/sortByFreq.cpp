#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Convert map to vector of pairs for sorting
        vector<pair<char, int>> charFreq(freq.begin(), freq.end());

        // Sort descending by frequency
        sort(charFreq.begin(), charFreq.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string result = "";
        for (auto &[ch, count] : charFreq) {
            result.append(count, ch);  // Append character count times
        }

        return result;
    }
};


int main() {
    Solution sol;
    string input = "tree";
    string result = sol.frequencySort(input);
    cout << "Sorted by frequency: " << result << endl;
    return 0;
}