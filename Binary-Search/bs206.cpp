#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int minCap = *max_element(weights.begin(), weights.end());
        int maxCap = accumulate(weights.begin(), weights.end(), 0);

        for (int capacity = minCap; capacity <= maxCap; ++capacity) {
            if (canShip(weights, D, capacity)) {
                return capacity;
            }
        }
        return maxCap; // fallback
    }

private:
    bool canShip(const vector<int>& weights, int D, int capacity) {
        int days = 1, currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                days++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return days <= D;
    }
};


int main() {
    Solution solution;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int D = 5;
    int result = solution.shipWithinDays(weights, D);
    cout << "Minimum capacity needed: " << result << endl;
    return 0;
}
// Time Complexity: O(n * log(sum(weights) - max(weights)))
// Space Complexity: O(1)
