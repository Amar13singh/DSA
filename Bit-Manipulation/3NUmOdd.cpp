#include<bits/stdc++.h>
using namespace std;


vector<int> findThreeOdd(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr)
        freq[num]++;

    vector<int> result;
    for (auto& [num, count] : freq) {
        if (count % 2 == 1)
            result.push_back(num);
    }

    return result; // Will contain 3 numbers
}
  int main() {
    vector<int> arr = {4, 2,2, 4, 5, 2, 3, 3, 5, 2, 4, 4, 4, 3, 3,3, 2};
    // vector<int>arr = {1, 2, 3, 2, 3, 1, 4, 5};
    vector<int> result = findThreeOdd(arr);
    cout << "Three numbers with odd occurrences: ";
    for (int num : result)
        cout << num << "  ";
    cout << endl;
    return 0;
}

