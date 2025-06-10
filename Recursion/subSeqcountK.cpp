#include <iostream>
#include <vector>
using namespace std;

int countSubsequences(int i, int sum, vector<int>& arr, int k) {
    if (i == arr.size()) {
        return (sum == k) ? 1 : 0;
    }

    // Pick current element
    int pick = countSubsequences(i + 1, sum + arr[i], arr, k);

    // Not pick current element
    int notPick = countSubsequences(i + 1, sum, arr, k);

    return pick + notPick;
}

int main() {
    vector<int> arr = {1, 2, 1};
    int k = 2;

    int total = countSubsequences(0, 0, arr, k);
    cout << "Total subsequences with sum " << k << " = " << total << endl;

    return 0;
}
