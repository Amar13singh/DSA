#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

//Tabulation method...
//state :--> similar as in memoization.. dp[l][r] < dp(l,r) >

// recurrence :--> dp[l][r] = max(left,right) 
//  where left = p[l]-dp[l+1][r]  right = p[r]-dp[l][r-1];

// base cases:--> dp[i][i] = p[i];

bool stoneGame(vector<int>& p){
    int n = p.size();

    //base cases..
    for(int i =0;i<n;i++){
        dp[i][i] = p[i];
    }

    for(int i = n-2;i>=0;i--){
        for(int j=i)
    }

}