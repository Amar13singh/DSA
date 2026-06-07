#include<bits/stdc++.h>
using namespace std;


//cycle detection using bfs ....
bool bfs(vector<vector<int>>& mat,int start,vector<int>& vis){
    queue<pair<int,int>> q;
    vis[start]= 1;
    q.push({start,-1});

    while(!q.empty()){
        auto[node,parent]= q.front();
        q.pop();

        for(int x:mat[node]){
            if(!vis[x]){
                vis[x] = 1;
                q.push({x,node});
            }
            else if(x!=parent) return true;
        }
    }
    return false;

}


bool isCycle(vector<vector<int>> &mat){
    int n = mat.size();
    vector<int> vis(n,0);

    for(int i = 0;i<n;i++){
        if(!vis[i]){
            if(bfs(mat,i,vis)){
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