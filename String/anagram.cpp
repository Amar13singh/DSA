#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int count[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};
  int main(){
    string s = "anagram";
    string t = "nagaram";
    Solution sol;
    bool result = sol.isAnagram(s, t);
    cout << "Is Anagram: " << (result ? "True" : "False") << endl;
    return 0;
  }