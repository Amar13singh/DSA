#include<bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int sum = 0;
    unordered_map<int, int> seen;
    seen[0] = 1; 
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];                         
        
        // if(seen.find((sum%k+k)%k)!=seen.end()) count+=seen[(sum%k+k)%k];

        int mod = (sum%k+k)%k;
        count += seen[mod];
        seen[mod]++;                            
    }

    return count;
        
    }

    int main(){
        vector<int> nums={4,5,0,-2,-3,1};
        int k=5;
        cout<<"Count: ";
        cout<<subarraysDivByK(nums,k);
        return 0;
    }