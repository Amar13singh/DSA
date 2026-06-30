#include<bits/stdc++.h>
using namespace std;

//index..
// parent=(i-1)/2;
// left=2i+1;
// right=2i+2



void heapifyUp(vector<int>&res,int idx){
    //for max heap...

    // while(idx>0 && res[(idx-1)/2] < res[idx]){
    //     swap(res[(idx-1)/2],res[idx]);
    //     idx=(idx-1)/2;
    // }
    
    // for minheap()....
    while(idx>0 && res[(idx-1)/2] > res[idx]){
        swap(res[(idx-1)/2],res[idx]);
        idx=(idx-1)/2;
    }

}

vector<int> buildHeap(vector<int>& arr){
    vector<int> res;

    for(int i=0;i<arr.size();i++){
        res.push_back(arr[i]);
        heapifyUp(res,res.size()-1);
    }
    return res;

}

int main(){
    vector<int> nums ={ 40,70,20,100,10,90,80,60,50,30 };
    vector<int> arr = buildHeap(nums);
    // cout<<"Min Heap:";
    cout<<"Max Heap";
    for(int x:arr){
        cout<<x<<" ";
    }
}