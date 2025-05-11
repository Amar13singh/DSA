#include <iostream>
#include <vector>
using namespace std;



int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size();  // Note: high = size, not size - 1

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    return low;  // Insertion point (or index if found)
}


int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    int index = searchInsert(nums, target);
    cout << "Index: " << index << endl;
    return 0;
}