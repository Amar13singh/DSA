#include<bits/stdc++.h>
using namespace std;


//dfs recursive way ...
bool dfs(int node,int parent,vector<vector<int>>& mat,vector<int>& vis){
    vis[node] = 1;
    int n= mat.size();

    for(int x:mat[node]){
        if(!vis[x]){
            if(dfs(x,node,mat,vis)) return true;
        }
        else if(x!=parent) return true; // main code for checking cycle......

    }
    return false;
}


bool isCycle(vector<vector<int>>& mat){
    int n= mat.size();
    vector<int> vis(n,0);

    for(int i = 0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,-1,mat,vis)) return true;
        }
    }
    return false;
}


int main(){
    vector<vector<int>> adj =
    {
        {1,3},   // 0
        {0,2},   // 1
        {1,3},   // 2
        {0,2}    // 3
    };

    vector<vector<int>> adj1 =
{
    {1},        // 0
    {0,2},      // 1
    {1},        // 2

    {4,5},      // 3
    {3,5},      // 4
    {3,4}       // 5
};

    cout << (isCycle(adj1) ? "Cycle Found" : "No Cycle");

    return 0;


}