#include <iostream>
#include <vector>
using namespace std;


//when there is duplicates in array .......
//faang favourite....
int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else if (nums[mid] < nums[high]) {
            high = mid;
        } else {
            high--; // Can't decide, reduce high by 1
        }
    }

    return nums[low];
}


int main() {
    vector<int> nums = {4, 5, 6, 7, 3 ,1, 1, 0, 0, 2};
    int minElement = findMin(nums);
    cout << "Minimum element: " << minElement << endl;
    return 0;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)