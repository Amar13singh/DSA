#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    string largestOddNumber(string num) {
        // Traverse from the end to find the rightmost odd digit
        for (int i = num.length() - 1; i >= 0; --i) {
            char ch = num[i];
            if ((ch - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit found
        return "";
    }
};

int main() {
    Solution solution;
    string num = "52";
    string result = solution.largestOddNumber(num);
    cout << "Largest Odd Number: " << result << endl;
    return 0;
}