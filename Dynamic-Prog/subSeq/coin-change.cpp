#include<bits/sdtc++.h>
using namespace std;

// coin change-1.. probleem is a optimization dp problem...

//Approach: 


// state:-- dp(i,amt);   //2d dp unavoidable in memoization

// base case: 


int solve(){

}

int coinChange(vector<int>& coins,int amount){
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,0));

    int ans = solve(n-1,amount,coins,dp);

    if(ans==INF) return -1;

    return ans;
}