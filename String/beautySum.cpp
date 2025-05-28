#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freq;
            map<int, int> countFreq; // freq -> count

            for (int j = i; j < n; ++j) {
                char c = s[j];

                // Update frequency map
                if (freq[c] > 0)
                    countFreq[freq[c]]--;  // remove old count
                freq[c]++;
                countFreq[freq[c]]++;     // add new count

                // Clean-up old frequency from countFreq
                if (countFreq[freq[c]-1] == 0)
                    countFreq.erase(freq[c]-1);

                // Now the smallest and largest freq is from countFreq map
                int minFreq = countFreq.begin()->first;
                int maxFreq = countFreq.rbegin()->first;

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};


int main() {
    Solution sol;
    string s = "aabcb";
    int result = sol.beautySum(s);
    cout << "Beauty sum: " << result << endl;
    return 0;
}