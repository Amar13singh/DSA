#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums, int k) {
        int left = 0, right = 0, odd = 0, maxLen = 0;
        int n = nums.size();

        for (right = 0; right < n; ++right) {
            if (nums[right] % 2 == 1) odd++;

            while (odd > k) {
                if (nums[left] % 2 == 1) odd--;
                left++;
            }

            if (odd == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};


int main(){
    vector<int> nums={1,3,2,2,4,3};
    int k=3;
    Solution obj;
    cout<<"max len: ";
    cout<<obj.longestNiceSubarray(nums,k);
    return 0;
}