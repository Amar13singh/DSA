#include<iostream>
#include<vector>
using namespace std;


int countOccurrences(vector<int>& nums, int target) {
    int n = nums.size();
    int first = -1, last = -1;
    
    // Find first occurrence
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Find last occurrence
    low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (first == -1 || last == -1)
        return 0;

    return last - first + 1;
}


int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    int count = countOccurrences(nums, target);
    cout << "Count of " << target << ": " << count << endl;
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)