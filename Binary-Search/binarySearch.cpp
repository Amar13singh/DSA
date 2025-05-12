#include <bits/stdc++.h>
using namespace std;


int findPivot(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) low = mid + 1;
        else high = mid;
    }
    return low;
}

int binarySearch(vector<int>& nums, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = findPivot(nums);

    if (nums[pivot] <= target && target <= nums[n - 1])
        return binarySearch(nums, pivot, n - 1, target);
    else
        return binarySearch(nums, 0, pivot - 1, target);
}
 int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int index = search(nums, target);
    cout << "Index: " << index << endl;
    return 0;
}