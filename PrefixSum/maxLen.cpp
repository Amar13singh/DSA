#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> mp; // sum -> earliest index
    mp[0] = -1;
    int sum = 0, maxLen = 0;

    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if(mp.count(sum - k)) {
            maxLen = max(maxLen, i - mp[sum - k]);
        }
        if(!mp.count(sum)) mp[sum] = i;
    }

    return maxLen;
}
 int main(){
    auto start = high_resolution_clock::now();
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    cout<<"max len: ";
    cout<<maxSubArrayLen(nums,k)<<endl;

    auto stop = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;
    return 0;
 }