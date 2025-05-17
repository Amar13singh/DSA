#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    bool canPlaceCows(vector<int>& stalls, int cows, int minDist) {
        int count = 1;
        int lastPlaced = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPlaced >= minDist) {
                count++;
                lastPlaced = stalls[i];
            }
            if (count >= cows) return true;
        }

        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls.back() - stalls[0];
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                result = mid;        // Try for a bigger distance
                low = mid + 1;
            } else {
                high = mid - 1;      // Try for a smaller distance
            }
        }

        return result;
    }
};

int main(){
    Solution solution;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    int result = solution.aggressiveCows(stalls, k);
    cout << "The largest minimum distance is: " << result << endl;
}

// Time Complexity: O(n * log(max(stalls)))
// Space Complexity: O(1)


