#include<bits/stdc++.h>
using namespace std;


//cycle detection in directed graph using dfs....

bool dfs(int node,vector<vector<int>> & mat,vector<int>& vis,vecotr<int> & pathvis){
    vis[node]=1;
    pathvis[node]= 1;

    for(int x:mat[node]){
        if(!vis[x]){
            if(dfs(x,mat,vis,pathvis)) return true;
        }else if(pathvis[x]) return true;
    }
    pathvis[node]=0;
    return false;
}




bool isCycle(vector<vector<int>> &mat){
    int n = mat.size();
    vector<int> vis(n,0);
    vector<int> pathvis(n,0);

    for(int i = 0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,mat,vis,pathvis)){
                return true;
            }
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