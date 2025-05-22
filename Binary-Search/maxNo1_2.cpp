#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rowWithMaxOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int maxRow = -1;
        int j = m - 1; // start from top-right
        
        for (int i = 0; i < n; i++) {
            // Move left while you see 1
            while (j >= 0 && mat[i][j] == 1) {
                j--;          // move left
                maxRow = i;   // update row index
            }
        }
        
        return maxRow;
    }
};
  int main(){
    vector<vector<int>> mat = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    Solution sol;
    int maxRow = sol.rowWithMaxOnes(mat);
    cout << "Row with maximum 1s: " << maxRow+1 << endl;
    return 0;
  }
//   Time Complexity: O(n + m)
// Space Complexity: O(1)