#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k) {
    int bouquets = 0, flowers = 0;

    for (int b : bloomDay) {
        if (b <= day) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0; // reset if flower not bloomed
        }
    }

    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long total = 1LL * m * k;
    if (total > bloomDay.size()) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canMakeBouquets(bloomDay, mid, m, k)) {
            answer = mid;
            high = mid - 1; // try earlier day
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    int result = minDays(bloomDay, m, k);
    cout << "Minimum days required: " << result << endl;
    return 0;
}

// Time Complexity: O(n log m)
// Space Complexity: O(1)