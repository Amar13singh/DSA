#include <bits/stdc++.h>
using namespace std;

class DAGShortestPath {
public:

    void dfs(
        int node,
        vector<vector<pair<int,int>>>& adj,
        vector<int>& vis,
        stack<int>& st)
    {
        vis[node] = 1;

        for(auto &[nbr, wt] : adj[node])
        {
            if(!vis[nbr])
                dfs(nbr, adj, vis, st);
        }

        st.push(node);
    }

    vector<int> shortestPath(
        int n,
        vector<vector<pair<int,int>>>& adj,
        int src)
    {
        vector<int> vis(n,0);
        stack<int> st;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,st);
        }

        vector<int> dist(n,1e9);
        dist[src]=0;

        while(!st.empty())
        {
            int u=st.top();
            st.pop();

            if(dist[u]==1e9)
                continue;

            for(auto &[v,w]:adj[u])
            {
                if(dist[u]+w < dist[v])
                {
                    dist[v] = dist[u]+w;
                }
            }
        }

        return dist;
    }
};

int main()
{
    int n = 11;

    vector<vector<pair<int,int>>> adj(n);

    auto addEdge = [&](int u,int v,int w)
    {
        adj[u].push_back({v,w});
    };

    addEdge(0,1,2);
    addEdge(0,2,6);
    addEdge(0,7,10);

    addEdge(1,2,1);
    addEdge(1,3,2);
    addEdge(1,4,6);

    addEdge(2,4,1);

    addEdge(3,4,4);
    addEdge(3,5,3);

    addEdge(4,6,1);

    addEdge(5,6,-2);

    addEdge(7,8,5);

    addEdge(9,10,5);

    DAGShortestPath obj;

    vector<int> dist =
        obj.shortestPath(n,adj,0);

    cout << "Shortest Distances from Source 0\n\n";

    for(int i=0;i<n;i++)
    {
        cout << "Node " << i << " : ";

        if(dist[i]==1e9)
            cout << "INF";
        else
            cout << dist[i];

        cout << "\n";
    }

    return 0;
}