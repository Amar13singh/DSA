#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string makeOddPalindrome(string half) {
    string pal = half;
    for (int i = half.length() - 2; i >= 0; i--) {
        pal += half[i];  // skip middle digit for odd
    }
    return pal;
}

string makeEvenPalindrome(string half) {
    string pal = half;
    for (int i = half.length() - 1; i >= 0; i--) {
        pal += half[i];  // full mirror
    }
    return pal;
}

int nthMixedPalindrome(int n) {
    vector<int> palindromes;
    int half = 1;

    while (palindromes.size() < n) {
        string halfStr = to_string(half);
        int oddPal = stoi(makeOddPalindrome(halfStr));
        int evenPal = stoi(makeEvenPalindrome(halfStr));
        palindromes.push_back(oddPal);
        palindromes.push_back(evenPal);
        half++;
    }

    sort(palindromes.begin(), palindromes.end());
    return palindromes[n - 1];
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "The " << n << "th palindrome is: " << nthMixedPalindrome(n) << endl;
    return 0;
}
