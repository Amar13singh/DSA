#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int rowWithMaxOnes(vector<vector<int>>& mat) {
        int maxRowIndex = -1;
        int maxCount = 0;
        int cols = mat[0].size();

        for (int i = 0; i < mat.size(); ++i) {
            int index = firstOne(mat[i], cols);
            int count = cols - index;

            if (count > maxCount) {
                maxCount = count;
                maxRowIndex = i;
            }
        }

        return maxRowIndex;
    }

private:
    int firstOne(vector<int>& row, int cols) {
        int low = 0, high = cols - 1;
        int result = cols; // default if no 1 found

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1) {
                result = mid;
                high = mid - 1; // search left
            } else {
                low = mid + 1;  // search right
            }
        }
        return result;
    }
};


int main(){
    vector<vector<int>> mat = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    Solution solution;
    int maxRowIndex = solution.rowWithMaxOnes(mat);
    cout << "Row with the maximum number of 1s: " << maxRowIndex+1 << endl;
    return 0;

}
// Time Complexity: O(m * log n)
// Space Complexity: O(1)