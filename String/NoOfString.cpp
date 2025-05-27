#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcdef";
    unordered_set<string> unique_substrings; // For unique
    int total = 0;

    for (int i = 0; i < s.size(); ++i) {
        string temp = "";
        for (int j = i; j < s.size(); ++j) {
            temp += s[j];
            unique_substrings.insert(temp);
            total++; // if counting all substrings including duplicates
        }
    }

    cout << "Total substrings: " << total << endl;
    cout << "Unique substrings: " << unique_substrings.size() << endl;
    return 0;
}



// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// int countTotalSubstrings(string s) {
    // int n = s.length();
    // return n * (n + 1) / 2;
// }
// 

