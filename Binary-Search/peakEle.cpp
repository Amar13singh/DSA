#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int low = 0, high = cols - 1;

        while (low <= high) {
            int midCol = low + (high - low) / 2;
            int maxRow = 0;

            // Find the row with the max element in midCol
            for (int i = 0; i < rows; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            bool leftIsBigger = (midCol - 1 >= 0) && (mat[maxRow][midCol - 1] > mat[maxRow][midCol]);
            bool rightIsBigger = (midCol + 1 < cols) && (mat[maxRow][midCol + 1] > mat[maxRow][midCol]);

            if (!leftIsBigger && !rightIsBigger) {
                return {maxRow, midCol}; // Peak found
            } else if (leftIsBigger) {
                high = midCol - 1; // Go left
            } else {
                low = midCol + 1; // Go right
            }
        }

        return {-1, -1}; // Should never reach here
    }
};


int main() {
    Solution solution;
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };
    vector<int> peak = solution.findPeakGrid(mat);
    cout << "Peak element found at: (" << peak[0] << ", " << peak[1] << ")" << endl;
    return 0;
}