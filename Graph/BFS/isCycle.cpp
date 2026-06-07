#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& mat,int start,vector<int>& vis){
    queue<pair<int,int>> q;
    vis[start]= 1;
    q.push({start,-1});

    while(!q.empty()){
        auto[node,parent]= q.front();
        q.pop();

        for(int x:mat[node]){
            if(!vis[x]){
                vis[x] = 1;
                q.push({x,node})
            }
            else if(x!=parent) return true;
        }
    }
    return false;

}



bool isCycle(vector<vector<int>> &mat,int v){
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
    
}