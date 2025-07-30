#include<bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;

    int count = 0;
    int oddSum = 0;

    for (int num : nums) {
        // Convert number to 1 if odd, else 0
        oddSum += (num % 2);

        // If we saw (oddSum - k) before, that means a subarray with exactly k odds ends here
        count += prefixCount[oddSum - k];

        // Store current oddSum
        prefixCount[oddSum]++;
    }

    return count;
}



int main(){
    vector<int> nums={1,1,2,1,1};
    int k=3;
    cout<<"Count of Subarrays: ";
    cout<<numberOfSubarrays(nums,k);
    return 0;
}