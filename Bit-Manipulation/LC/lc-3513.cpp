#include<bits/stdc++.h>
using namespace std;

//Concepts...
// 

int xorTriplets(vector<int>&nums){
    int n = nums.size();

    if(n<=2) return n;

    int ans = 1;
    while(ans<=n) ans<<=1;

    return ans;

}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    cout<<"ans is:"<<xorTriplets(arr);

}