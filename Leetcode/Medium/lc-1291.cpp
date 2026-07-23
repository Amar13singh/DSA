#include<bits/stdc++.h>
using namespace std;


//faang Qs...
vector<int> seqDigit(int low,int high){
    vector<int>ans;

    for(int start = 1;start<=9;start++){
        int num = 0;
        for(int dig = start;dig<=9;dig++){
            num = num*10+dig;

            if(num>=low && num<=high) ans.push_back(num);

            if(num>high) break;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int low = 100;
    int high = 1000000000;//highest num allowed in int....

    vector<int> arr = seqDigit(low,high);
    cout<<"Ans is: ";
    for(int x:arr) cout<<x<<" ";
}