#include<bits/stdc++.h>
using namespace std;

int peakEle(vector<int> & arr){
    int n= arr.size();
    int low = 0;
    int high = n-1;

    while(low<high){
        int mid = low+(high-low)/2;

        if(arr[mid]>arr[mid+1]) high = mid;
        else low = mid+1;

    }
    return low;
}


int main(){
    vector<int> arr = {1,3,1,2,4,1,5,6,3};
    cout<<"Ans is:"<<peakEle(arr);
    return 0;
}