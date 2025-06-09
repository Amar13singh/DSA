#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--; // because we start from 1, so we already count 1 as the first
        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }

    long long countSteps(int n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            steps += min(n + 1LL, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};
int main(){
    Solution sol;
    int n = 13, k = 2;
    cout<<"The kth smallest number is: ";
    cout << sol.findKthNumber(n, k) << endl;
    return 0;
}