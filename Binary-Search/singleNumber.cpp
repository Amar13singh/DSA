#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is even
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;  // valid pair
            } else {
                high = mid - 1; // single element is before
            }
        } else {
            if (nums[mid] == nums[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return nums[low];
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int single = singleNonDuplicate(nums);
    cout << "Single element: " << single << endl;
    return 0;
}