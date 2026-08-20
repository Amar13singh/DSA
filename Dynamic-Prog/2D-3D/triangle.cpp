#include<bits/stdc++.h>
using namespace std;

//lc-120..
//memoization.. top-down


int solve(vector<vector<int>>& tri,int i,int j,vector<vector<int>>& dp){
    int n = tri.size();

    //base case..
    if(i==n-1) return tri[i][j];

    if(dp[i][j]!=INT_MAX) return dp[i][j];

    //recurrence..
    return dp[i][j] = tri[i][j]+ min(
        solve(tri,i+1,j,dp),
        solve(tri,i+1,j+1,dp)
    );

}



int minTotal(vector<vector<int>>& tri){
    int n = tri.size();
    
    //base case is here last row 
    vector<vector<int>>dp(n);
    for(int i=0;i<n;i++){
        dp[i]=vector<int>(i+1,INT_MAX);
    }
    return solve(tri,0,0,dp);
}


int main(){
    vector<vector<int>> tri = {{2},{3,4},{6,5,7},{4,2,8,3}};
    int ans = minTotal(tri);
    cout<<"ans is:"<<ans;
}



// Time  = O(n²)
// Space = O(n²) + O(n)
//       = O(n²)