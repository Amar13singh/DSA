#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;  // stores indices
        int water = 0;

        for (int i = 0; i < n; i++) {
            // While stack is not empty and current height is greater than the height at top index
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty())
                    break;

                int left = st.top();  // now this is the left boundary
                int distance = i - left - 1;
                int bounded_height = min(height[i], height[left]) - height[top];

                water += distance * bounded_height;
            }

            st.push(i);
        }

        return water;
    }
};
int main() {
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = solution.trap(height);
    cout << "Trapped Water: " << trappedWater << endl;
    return 0;
}