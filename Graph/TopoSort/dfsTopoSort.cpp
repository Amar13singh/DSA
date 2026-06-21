#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>& mat,stack<int>& st,vector<int>&vis){
    vis[node]=1;
    for(int x:mat[node]){
        if(!vis[x]) dfs(x,mat,st,vis);
    }
    st.push(node);
}

vector<int> topoSort(vector<vector<int>>& mat){
    int n = mat.size();
    stack<int>st;
    vector<int> vis(n,0);

    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,mat,st,vis);
    }

    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}


int main() {

vector<vector<int>> adj = {
    {},      // 0
    {},      // 1
    {3},     // 2 -> 3
    {1},     // 3 -> 1
    {0,1},   // 4 -> 0,1
    {0,2}    // 5 -> 0,2
};


vector<vector<int>> adj1 = {
    {1},    // 0 -> 1
    {},     // 1
    {3},    // 2 -> 3
    {},     // 3
    {5},    // 4 -> 5
    {},     // 5
    {}      // 6 isolated
};


vector<vector<int>> adj2 = {
    {1},    // 0 -> 1
    {2},    // 1 -> 2
    {0,3},  // 2 -> 0,3
    {}      // 3
};


    vector<int> ans = topoSort(adj);

    cout << "Topological Order: ";

    for(int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}