#include<bits/stdc++.h>
using namespace std;

vector<int> firstNlast(vector<int> arr,int target){
    int n = arr.size();
    int low=0,high=n-1;
    int first = -1,last = -1;

    //first occ of ele....
    while(low<=high){
        int mid = low+(high-low)/2;

        if(arr[mid]==target){
            first = mid;
            high = mid-1;
        }else if(arr[mid]<target){
            low = mid+1;
        }else high = mid-1;
    }


//last occ of ele..
low = 0;high =n-1;

while(low<=high){
        int mid = low+(high-low)/2;

        if(arr[mid]==target){
            last = mid;
            low = mid+1;
        }else if(arr[mid]<target){
            low = mid+1;
        }else high = mid-1;
    }
    return {first,last};
}


int main(){
    vector<int> arr={1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,6,6,6,6,7,7,8,8,9,9,9};
    vector<int> ans = firstNlast(arr,3);
    cout<<"First and last occurence is:"<<ans[0]<<" "<<ans[1];
    return 0;
}