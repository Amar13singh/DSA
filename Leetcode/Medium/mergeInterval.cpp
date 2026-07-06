#include<bits/stdc++.h>
using namespace std;


//sorting method used for this....
int removeinterval(vector<vector<int>>&intervals){
    int n = intervals.size();
    sort(intervals.begin(),intervals.end(),
            [](vector<int>&a,vector<int>&b){
                if(a[0]=b[0]) return a[1]>b[1];
                return a[0]<b[0];
            });

    int ans = 0;
    int maxEnd = intervals[0][1];

    for(int i=1;i<n;i++){
        if(intervals[i][1]>maxEnd){
            ans++;
            maxEnd=interval[i][1];
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,4},{3,6},{2,8}};
    int ans = removeinterval(intervals);

    cout<<"Ans is:"<<ans;
    

}