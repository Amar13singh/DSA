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
    dp.assign(n,vector<int>(n,INT_MIN));


    //base cases..
    for(int i=0;i<n;i++){
        dp[i][i] = p[i];
    } 

     //diagonal is base case actually that why when we traverse and store ans in dp 
    // the value l<r very imp bcz other than this become invalid...


    //very important in tabulation is to visualise filing order in table and acc
    // decide to use loop range ,even slight mistake can make sol wrong...

    for(int l=n-1;l>=0;l--){
        for(int r=l+1;r<n;r++){
            dp[l][r] = max(
                p[l]-dp[l+1][r],
                p[r]-dp[l][r-1]
            );
        }
    }

    return dp[0][n-1]>0;

}

int main(){
    vector<int> arr ={5,3,4,5};


    stoneGame(arr)?cout<<"yes":cout<<"No";
}
