#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int>& nums) {
    int n = nums.size();
    int total = 1 << n; // 2^n subsets
    vector<vector<int>> result;

    for (int i = 0; i < total; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {         // Check if j-th bit is set
                subset.push_back(nums[j]);
            }
        }
        result.push_back(subset);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = powerSet(nums);

    cout << "Power set:\n";
    for (auto& subset : result) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
