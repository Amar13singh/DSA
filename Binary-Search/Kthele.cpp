#include <bits/stdc++.h>    
using namespace std;

int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n1 = arr1.size(), n2 = arr2.size();

    // Ensure arr1 is the smaller array
    if (n1 > n2) return kthElement(arr2, arr1, k);

    int low = max(0, k - n2), high = min(k, n1);

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return -1; // error
}


int main() {
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;
    int result = kthElement(arr1, arr2, k);
    cout << "The " << k << "th element is: " << result << endl;
}
// Time Complexity: O(log(min(m, n)))
// Space Complexity: O(1)