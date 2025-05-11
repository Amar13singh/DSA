#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size(); // note: not size()-1

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < x)
            low = mid + 1; // discard left half
        else
            high = mid; // keep mid, may be answer
    }

    return low; // Index of first element >= x
}

int main() {
    vector<int> arr = {2, 4, 4, 4, 7, 10, 14};
    int x = 4;

    int idx = lowerBound(arr, x);
    if (idx < arr.size())
        cout << "Lower bound of " << x << " is at index " << idx
             << " (value: " << arr[idx] << ")" << endl;
    else
        cout << "No element ≥ " << x << " found." << endl;

    return 0;
}
