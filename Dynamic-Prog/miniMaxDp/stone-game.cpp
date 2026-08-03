#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>dp;

//method 1 : memoization--> top-down approach..

// state:--> dp(i,j);

// transition:--> take left dp(l+1,r) or right dp(l,r-1)

//smart move:---
// main concept in this is that we are not taking separate dp for both alice/bob 
// we are storing diff of their score.. thats why we need just one dp..

//recurrence:--> dp(l,r) = max( left,right)  where left = p[l]-dp(l+1,r)  right = p[r]-dp(l,r-1)

// base case:--> when only one element left dp(i,i) = p[i];


int solve(vector<int>& nums,int l ,int r){
    if(l==r) return nums[l];

    if(dp[l][r]!=INT_MIN) return dp[l][r];

    int left = nums[l]-solve(nums,l+1,r); //diff alic-bob
    int right = nums[r]-solve(nums,l,r-1);

    return dp[l][r] = max(left,right);

}


bool stoneGame(vector<int>& nums){
    int n = nums.size();

    dp.assign(n,vector<int>(n,INT_MIN));
    int l=0,r=n-1;

    return solve(nums,l,r) > 0;
}

int main(){
    vector<int> arr ={5,3,4,5};

    stoneGame(arr)?cout<<"yes":cout<<"No";
}

