#include<bits/stdc++.h>
using namespace std;

// tabulation method:--> bottom up dp..

// state:--> index(i)
// recurrence:--> bcz it depends upn prev 2 value 
// dp[i] = dp[i-1]+dp[i-2];

//base cases:-- dp[0] = 0; dp[1] = 1;  //very very imporatant...
///it decide how will we traverse array/grid...



int fib(int n){
    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 41;
    
    cout<<"Ans is: "<<fib(n);

}