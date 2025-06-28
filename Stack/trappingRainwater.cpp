#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        for (int i = 1; i < n - 1; i++) {
            int leftMax = 0, rightMax = 0;

            // Find left max
            for (int j = i; j >= 0; j--)
                leftMax = max(leftMax, height[j]);

            // Find right max
            for (int j = i; j < n; j++)
                rightMax = max(rightMax, height[j]);

            water += min(leftMax, rightMax) - height[i];
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