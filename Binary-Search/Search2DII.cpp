#include <bits/stdc++.h>
using namespace std;

//on if the matrix is sorted in both row and column wise
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m - 1;

        while (row < n && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) col--;
            else row++;
        }

        return false;
    }
};
int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    Solution sol;
    bool found = sol.searchMatrix(matrix, target);
    cout << (found ? "Found" : "Not Found") << endl;
    return 0;
}
// Time Complexity: O(m + n)
// Space Complexity: O(1)