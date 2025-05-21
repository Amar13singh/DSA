#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return true;

        // Skip duplicates
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
        }
        // Left half is sorted
        else if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    bool found = search(nums, target);
    cout << "Target " << target << " found: " << (found ? "Yes" : "No") << endl;
    return 0;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)