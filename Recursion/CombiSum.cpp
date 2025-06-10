#include<bits/stdc++.h>
using namespace std;


// Subsets (LC 78)
void generate(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans,int k) {
    int sum = 0;
    // if (i == nums.size()) {
        if(sum == k){
        ans.push_back(curr);
        return;
        // }
    }
    curr.push_back(nums[i]);
    sum += nums[i];
    generate(i + 1, nums, curr, ans,k);
    curr.pop_back();
    generate(i + 1, nums, curr, ans,k);
}

int main() {
    vector<int> nums = {1, 2, 3};
    int K = 3;
    vector<vector<int>> ans;
    vector<int> curr;
    generate(0, nums, curr, ans,K);
    for (auto v : ans) {
        for (auto x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}