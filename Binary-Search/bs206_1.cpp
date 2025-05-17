#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());  // Minimum capacity
        int high = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Current capacity to test
            if (canShip(weights, days, mid)) {
                result = mid;
                high = mid - 1;  // Try smaller capacity
            } else {
                low = mid + 1;   // Try larger capacity
            }
        }
        return result;
    }

private:
    bool canShip(const vector<int>& weights, int D, int capacity) {
        int currentLoad = 0;
        int daysNeeded = 1;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                daysNeeded++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return daysNeeded <= D;
    }
};

int main() {
    Solution solution;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int result = solution.shipWithinDays(weights, days);
    cout << "Minimum capacity needed: " << result << endl;
    return 0;
}

// Time Complexity: O(n * log(sum(weights)))
// Space Complexity: O(1)