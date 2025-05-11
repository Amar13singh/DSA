#include <iostream>
#include <vector>
using namespace std;

int upperBound(const vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size(); // Note: high = n, not n - 1

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x)
            low = mid + 1; // x is too small, go right
        else
            high = mid;    // might be the upper bound
    }

    return low; // Index of first element > x
}

int main() {
    vector<int> arr = {2, 4, 4, 4, 7, 10, 14};
    int x = 4;

    int idx = upperBound(arr, x);
    if (idx < arr.size())
        cout << "Upper bound of " << x << " is at index " << idx
             << " (value: " << arr[idx] << ")" << endl;
    else
        cout << "All elements are ≤ " << x << endl;

    return 0;
}
