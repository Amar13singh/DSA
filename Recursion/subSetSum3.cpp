#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    void subset(int idx, vector<int>& nums, vector<int> & sbset, vector<vector<int>> & ans){

        ans.push_back(sbset);
        for(int i= idx; i<nums.size(); i++){
            if(i != idx && nums[i] == nums[i-1]) continue;

            sbset.push_back(nums[i]); // include
            subset(i+1, nums, sbset, ans);
            sbset.pop_back();    //not incl
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sbset;
        sort(nums.begin(), nums.end());
        subset(0, nums, sbset, ans);

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}