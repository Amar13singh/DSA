#include <bits/stdc++.h>
using  namespace std;

class Solution {
public:
    int countSmallerThanEqual(const vector<int>& row, int target) {
        return upper_bound(row.begin(), row.end(), target) - row.begin();
    }

    int findMedian(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        // Find min and max values in the matrix
        for (int i = 0; i < r; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][c - 1]);
        }

        int desired = (r * c + 1) / 2;  // Median position (1-based)

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 0; i < r; i++) {
                count += countSmallerThanEqual(matrix[i], mid);
            }

            if (count < desired)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    Solution sol;
    int median = sol.findMedian(matrix);
    cout << "Median: " << median << endl;
    return 0;

}


