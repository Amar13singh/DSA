#include<bits/stdc++.h>
using namespace std;


int countSubArray(vector<int>& nums,int key){
    int sum = 0;
    unordered_map<int,int> seen;
    seen[sum]=1;//0 one time
    int count = 0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        count+=seen[sum-key];//check for sum-key in seen
        seen[sum]++;

    }
    return count;

}

int main(){
    vector<int> arr = {1,2,3,4,1,2,1,3,4};
    int key = 10;
    cout<<"Number of Subarray:";
    cout<<countSubArray(arr,key);
    return 0;
}