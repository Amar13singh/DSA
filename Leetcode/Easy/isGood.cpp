#include<bits/stdc++.h>
using namespace std;

bool isGood(vector<int>& nums){
    int n = nums.size()-1;
    sort(nums.begin(),nums.end());
    for(int i = 0;i<n;i++){
        if(nums[i]!=i+1) return false;
    }
    return nums[n] == n;
}

int main(){
    vector<int> arr = {1,2,3,3};
    isGood(arr)==1?cout<<"yes":cout<<"NO";
}