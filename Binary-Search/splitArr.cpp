#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int maxSum) {
        int count = 1; // start with one subarray
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                count++;
                currentSum = num; // start new subarray
                if (count > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};


int main(){
    Solution solution;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    int result = solution.splitArray(nums, k);
    cout << "The minimum largest sum of the subarrays is: " << result << endl;
}

// Time Complexity: O(n * log(sum(nums)))
// Space Complexity: O(1)