#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;



class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> count;

        for (char c : s) count[c]++;
        for (char c : t) {
            if (--count[c] < 0) return false;
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