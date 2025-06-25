#include<bits/stdc++.h>
using namespace std;


vector<int> countNGEs(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);

    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] > nums[i]) {
                ++count;
            }
        }
        res[i] = count;
    }

    return res;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = countNGEs(nums);
    cout << "Right Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}