#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int cnt = 0;

int fib(int n){

    // cnt++;
    // cout<<dp[n]<<"  ";

    if(n<=1) return n;
    
    // if(dp[n-1]!=-1) return dp[n-1];
    if(dp[n]!=-1) return dp[n];


    
    dp[n] = fib(n-1)+fib(n-2);
    dp[n-1] = fib(n-1)+fib(n-2);
    // return fib(n-1)+fib(n-2);

    cnt++;
    cout<<dp[n]<<"  ";

    return dp[n];


}

int main(){
    int n = 15;
    dp.assign(n+1,-1);
    int ans = fib(n);
    cout<<"\nAns is: "<<ans<<endl;
    cout<<"Recursion cnt is: "<<cnt;

}