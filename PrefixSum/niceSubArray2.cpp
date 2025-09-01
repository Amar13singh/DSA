#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


//sliding window approach.......
class Solution {
public:
    int shortestNiceSubarray(vector<int>& nums, int k) {
        int left = 0, right = 0, odd = 0;
        int n = nums.size(), minLen = INT_MAX;

        for (right = 0; right < n; ++right) {
            if (nums[right] % 2 == 1) odd++;//expanding the window

            while (odd > k) {        //shrinking the window
                if (nums[left] % 2 == 1) odd--;
                left++;
            }

            if (odd == k) {
                minLen = min(minLen, right - left + 1);
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main(){
    auto start = high_resolution_clock::now();
    vector<int> nums={1,3,3,2,4,3};
    int k=3;
    Solution obj;
    cout<<"min len: ";
    cout<<obj.shortestNiceSubarray(nums,k)<<endl;

    auto stop = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;
    return 0;
}
