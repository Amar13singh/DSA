#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0, num = 1;
        while (k > 0) {
            if (i < arr.size() && arr[i] == num) {
                i++;
            } else {
                k--;
                if (k == 0) return num;
            }
            num++;
        }
        return -1; // should never reach
    }
};

int main(){
Solution solution;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int result = solution.findKthPositive(arr, k);
    cout << "The " << k << "th missing positive integer is: " << result << endl;
}
// Time Complexity: O(n)
// Space Complexity: O(1)