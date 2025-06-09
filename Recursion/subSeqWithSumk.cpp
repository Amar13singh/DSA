#include <iostream>
#include <vector>
using namespace std;

bool checkSum(int i, int sum, vector<int>& arr, int k) {
    if (sum == k) return true;
    if (i == arr.size()) return false;

    // Pick the current element
    if (checkSum(i + 1, sum + arr[i], arr, k)) return true;

    // Not pick the current element
    if (checkSum(i + 1, sum, arr, k)) return true;

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int k = 5;

    if (checkSum(0, 0, arr, k)) 
        cout << "Yes, a subsequence with sum " << k << " exists.\n";
    else 
        cout << "No subsequence with sum " << k << " found.\n";

    return 0;
}
