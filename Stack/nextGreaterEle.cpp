#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreater;
        stack<int> stk;

        for (int num : nums2) {
            while (!stk.empty() && stk.top() < num) {
                nextGreater[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(nextGreater.count(x) ? nextGreater[x] : -1);
        }
        return ans;
    }
};
 int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    cout << "Next Greater Elements: [";
    for (int num : result) {
        cout << num << " ";
    }
    cout << "]" << endl;
    return 0;
}