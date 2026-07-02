#include<bits/stdc++.h>
using namespace std;



void maxHeapify(vector<int>&arr,int n,int i){
    int lg = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if (l < n && arr[l] > arr[lg])
            lg = l;

        if (r < n && arr[r] > arr[lg])
            lg = r;

        if (lg != i)
        {
            swap(arr[i], arr[lg]);
            maxHeapify(arr, n, lg);
        }

}

void convertMinToMax(vector<int>& arr){
    int n = arr.size();

    for(int i=n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);

    }
}

int main(){
    vector<int> arr1={10,20,40,50,30,90,80,100,60,70};
    convertMinToMax(arr1);
    cout<<"max heap is: ";
    for(int x:arr1) cout<<x<<" ";

}