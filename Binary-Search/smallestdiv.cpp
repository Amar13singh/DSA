#include<bits/stdc++.h>
using namespace std;




int computeSum(const vector<int>& nums, int d) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + d - 1) / d;  // Equivalent to ceil(num / d)
        }
        return sum;
    }
    
int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (computeSum(nums, mid) <= threshold) {
                answer = mid;
                high = mid - 1;  // Try smaller divisor
            } else {
                low = mid + 1;   // Need bigger divisor
            }
        }

        return answer;
    }

int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    int result = smallestDivisor(nums, threshold);
    cout << "Smallest divisor: " << result << endl;
    return 0;
}
// Time Complexity: O(n * log(max(nums)))
// Space Complexity: O(1)

