#include<bits/stdc++.h>
using namespace std;


bool dfs(int node,vector<vector<int>>& graph,vector<int>& col,int clr){
    col[node] = clr;

    for(int x:graph[node]){
        if(col[x]==-1){
            if(!dfs(x,graph,col,1-clr)) return false;
        }
        else if(col[x]==col[node]) return false;
    }
    return true;
}



bool isBipartite(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> col(n,-1);
    for(int i=0;i<n;i++){
        if(col[i]==-1){
            if(!dfs(i,graph,col,0)) return false;

        }
    }
    return true;
}

//Driver code...
