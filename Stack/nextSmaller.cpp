#include<bits/stdc++.h>
using namespace std;


//using increasing stack
vector<int> nextSmallerElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);  // default to -1
        stack<int> st;  // stack stores elements

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                result[i] = st.top();
            }

            st.push(nums[i]);
        }

        return result;
    }

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextSmallerElement(nums);
    cout << "Next Smaller Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}