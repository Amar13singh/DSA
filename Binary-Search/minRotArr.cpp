#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Minimum is in the unsorted part
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    // low == high is the index of the minimum element
    return nums[low];
}


int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int minElement = findMin(nums);
    cout << "Minimum element: " << minElement << endl;
    return 0;
}

