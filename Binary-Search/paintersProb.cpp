#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& boards, int k, int maxTime) {
        int painters = 1;
        int currentSum = 0;

        for (int board : boards) {
            if (currentSum + board > maxTime) {
                painters++;
                currentSum = board;
                if (painters > k)
                    return false;
            } else {
                currentSum += board;
            }
        }
        return true;
    }

    int paintersPartition(vector<int>& boards, int k) {
        int low = *max_element(boards.begin(), boards.end());
        int high = accumulate(boards.begin(), boards.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(boards, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int result = solution.paintersPartition(boards, k);
    cout << "The minimum time required to paint the boards is: " << result << endl;
}   
// Time Complexity: O(n * log(sum of all elements of the array))
// Space Complexity: O(1)