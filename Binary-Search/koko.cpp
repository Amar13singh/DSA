#include <bits/stdc++.h>
using namespace std;


int getHours(const vector<int>& piles, int k) {
    int hours = 0;
    for (int pile : piles) {
        hours += (pile + k - 1) / k;
    }
    return hours;
}


int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int totalHours = getHours(piles, mid);

        if (totalHours <= h) {
            answer = mid;
            high = mid - 1; // try smaller k
        } else {
            low = mid + 1;  // need bigger k
        }
    }
    return answer;
}

int main() {
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;
    int result = minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;
    return 0;
}

// Time Complexity: O(n log m)
// Space Complexity: O(1)


