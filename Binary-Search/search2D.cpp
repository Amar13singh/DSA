#include <bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();           // number of rows
    int n = matrix[0].size();        // number of columns

    int low = 0, high = m * n - 1;   // binary search over the flattened array

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = mid / n;           // convert 1D index to 2D row
        int col = mid % n;           // convert 1D index to 2D col

        int midVal = matrix[row][col];

        if (midVal == target)
            return true;
        else if (midVal < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false; // target not found
}


int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    bool found = searchMatrix(matrix, target);  
    cout << (found ? "Found" : "Not Found") << endl;
    return 0;

}

// Time Complexity: O(log(m*n))
// Space Complexity: O(1)