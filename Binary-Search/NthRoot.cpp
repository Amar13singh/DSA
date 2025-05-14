#include<bits/stdc++.h> 
using namespace std;



double nthRoot(double x, int n) {
    double low = 0, high = max(1.0, x);
    double eps = 1e-6;

    while ((high - low) > eps) {
        double mid = (low + high) / 2.0;
        double power = pow(mid, n);

        if (power < x)
            low = mid;
        else
            high = mid;
    }

    return low; // or (low + high)/2 for better rounding
}

int main() {
    double x = 8;
    int n = 3;
    double result = nthRoot(x, n);
    cout << "The " << n << "th root of " << x << " is " << result << endl;
    return 0;
}
// Time Complexity: O(log(n))
// Space Complexity: O(1)