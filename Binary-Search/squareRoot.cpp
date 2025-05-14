#include<bits/stdc++.h> 
using namespace std;


int mySqrt(int x) {
    if (x < 2) return x;

    int low = 1, high = x / 2;
    int ans = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Use division to avoid overflow: mid <= x / mid
        if (mid <= x / mid) {
            ans = mid;      // store last valid result
            low = mid + 1;  // go right
        } else {
            high = mid - 1; // go left
        }
    }

    return ans;
}


int main() {
    int x = 8;
    int result = mySqrt(x);
    cout << "Square root of " << x << " is " << result << endl;
    return 0;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)