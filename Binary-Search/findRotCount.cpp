#include <iostream>
#include <vector>
using namespace std;

int findRotationCount(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        // If the array is already sorted
        if (nums[low] <= nums[high]) return low;

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        // Check if mid is the minimum
        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
            return mid;

        // Decide whether to go to left or right half
        if (nums[mid] >= nums[low])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0; // Default fallback
}
 int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int rotationCount = findRotationCount(nums);
    cout << "Rotation count: " << rotationCount << endl;
    return 0;
}