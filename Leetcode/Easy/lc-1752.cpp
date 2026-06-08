#include<bits/stdc++.h>
using namespace std;

//works even on duplicates...

bool rotatedAndSorted(vector<int>& arr){
    int n = arr.size();
    int cnt = 0;

    for(int i=0;i<n;i++){
        if(arr[i]>arr[(i+1)%n]) cnt++;
    }
    return cnt>1?false:true;
}

int main(){
    vector<int> nums = {3,4,5,1,2,2,3};
    rotatedAndSorted(nums)==1? cout<<"True":cout<<"False";
}


