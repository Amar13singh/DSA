#include<bits/stdc++.h>
using namespace std;


//prefix-Sum
vector<int>prefixSum(vector<int>& nums){
    int n = nums.size();
    vector<int> pre(n);
    pre[0]=nums[0];
    for(int i = 1;i<n;i++){
        pre[i]=pre[i-1] + nums[i];
    }
    return pre;
}


int main(){
    vector<int> arr={1,2,3,4,5,6};
    vector<int> pre = prefixSum(arr);
    cout<<"PrefixSum is:";
    int i=0;
    while(i < pre.size()){
        cout<<pre[i]<<" ";
        i++;
    }

}