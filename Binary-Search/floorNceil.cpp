#include <iostream>
#include <vector>
using namespace std;

pair<int, int> floorAndCeil(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int floor = -1, ceil = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            floor = ceil = arr[mid];
            break;
        }
        else if (arr[mid] < target) {
            floor = arr[mid];     // possible floor
            low = mid + 1;
        }
        else {
            ceil = arr[mid];      // possible ceiling
            high = mid - 1;
        }
    }

    return {floor, ceil};
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 6;

    auto [floorVal, ceilVal] = floorAndCeil(arr, target);

    cout << "Floor of " << target << " is " << floorVal << endl;
    cout << "Ceiling of " << target << " is " << ceilVal << endl;

    return 0;
}
