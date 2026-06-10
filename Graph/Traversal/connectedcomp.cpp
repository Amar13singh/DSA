#include<bits/stdc++.h>
using namespace std;


    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node] = 1;

        for(int nei : adj[node])  //due to adjacency list ...
        {
            if(!vis[nei])
            {
                dfs(nei, adj, vis);
            }
        }
    }

    int countComponents(vector<vector<int>>& adj)
    {
        int V = adj.size();

        vector<int> vis(V,0);

        int components = 0;

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                components++;
                dfs(i,adj,vis);
            }
        }

        return components;
    }


int main(){
    vector<vector<int>> adj = {
    {1},
    {0,2},
    {1},
    {4},
    {3}
};
    int ans = countComponents(adj);
    cout<<"Connected Components are:"<<ans;
}