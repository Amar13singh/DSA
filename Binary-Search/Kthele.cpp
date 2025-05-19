#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(const vector<int>& stations, int k, double dist) {
        int required = 0;

        for (int i = 1; i < stations.size(); ++i) {
            double gap = stations[i] - stations[i - 1];
            required += (int)(gap / dist); // floor
        }
        return required <= k;
    }

    double minmaxGasDist(vector<int>& stations, int k) {
        double low = 0.0;
        double high = stations.back() - stations.front(); // max distance
        double epsilon = 1e-6;

        while (high - low > epsilon) {
            double mid = (low + high) / 2.0;

            if (isPossible(stations, k, mid)) {
                high = mid; // try smaller max distance
            } else {
                low = mid; // need to allow larger distance
            }
        }
        return low;
    }
};


int main() {
    Solution solution;
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;
    double result = solution.minmaxGasDist(stations, k);
    cout << "Minimum maximum distance: " << result << endl;
    return 0;
}
