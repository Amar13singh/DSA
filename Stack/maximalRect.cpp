#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int maxArea = 0;
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);

        for (const auto& row : matrix) {
            for (int j = 0; j < cols; ++j) {
                // Update histogram height
                if (row[j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            // Apply Largest Rectangle in Histogram (Leetcode 84)
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // sentinel
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }

        return maxArea;
    }
};
 int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    Solution sol;
    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;
    return 0;
}