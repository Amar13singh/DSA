#include<bits/stdc++.h>
using namespace std;

pair<int, int> findTwoOddNumbers(const vector<int>& arr) {
    int xorAll = 0;
    for (int num : arr)
        xorAll ^= num;

    // Step 2: Get rightmost set bit
    int rightmostSetBit = xorAll & -xorAll;

    // Step 3: Divide into two groups and XOR separately
    int x = 0, y = 0;
    for (int num : arr) {
        if (num & rightmostSetBit)
            x ^= num;
        else
            y ^= num;
    }

    return {x, y};  // Two numbers with odd occurrences
}
  int main() {
    vector<int> arr = {4, 2, 4, 5, 2, 3, 3, 5, 2, 4, 4, 4, 3, 3, 2};
    // vector<int>arr = {1, 2, 3, 2, 3, 1, 4, 5};
    pair<int, int> result = findTwoOddNumbers(arr);
    cout << "Two numbers with odd occurrences: " << result.first << " and " << result.second << endl;
    return 0;
}