#include<bits/stdc++.h>
using namespace std;


void dfs(int start,vector<vector<int>> adj,vector<bool>& vis,vector<int>& ans){
    vis[start]=true;
    ans.push_back(start);
    for(int x:adj[start]){
        if(!vis[x]){
            // vis[x]=true;
            dfs(x,adj,vis,ans);
        }
    }
}

vector<int>dfsTr(vector<vector<int>> arr, int start){
    int n= arr.size();
    vector<bool> vis(n,false);
    // vis[start]=true;
    vector<int> ans;

    dfs(start,arr,vis,ans);
    return ans;
}


int main(){
    vector<vector<int>> arr={
        {1,2},
        {0,3,4},
        {0,5,6},
        {1},
        {1},{2},{2}
    };
    vector<int>ans = dfsTr(arr,0);
    for(int x:ans) cout<<x<<" ";
}

// Time Complexity:O(n+2e)
// space Complexity:O(n)