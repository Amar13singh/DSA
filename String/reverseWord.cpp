#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;

        // Step 1: Extract words (ignoring multiple spaces)
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Reverse the list of words
        std::reverse(words.begin(), words.end());

        // Step 3: Join with single space
        std::string result;
        for (size_t i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string output = sol.reverseWords(input);
    std::cout << "Reversed: \"" << output << "\"" << std::endl;

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)