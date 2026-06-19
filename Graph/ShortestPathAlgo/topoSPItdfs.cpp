#include <bits/stdc++.h>
using namespace std;


vector<int> shortestPath(int n,
        vector<vector<pair<int,int>>>& adj,int src){

        vector<int> vis(n,0);

        vector<int> topo;

        for(int start=0; start<n; start++)
        {
            if(vis[start]) continue;

            stack<pair<int,bool>> st;

            st.push({start,false});

            while(!st.empty())
            {
                auto [u, processed] = st.top();
                st.pop();

                if(processed)
                {
                    topo.push_back(u);
                    continue;
                }

                if(vis[u]) continue;

                vis[u]=1;

                st.push({u,true});

                for(int i=adj[u].size()-1;i>=0;i--)
                {
                    auto [v,w] = adj[u][i];

                    if(!vis[v])
                        st.push({v,false});
                }
            }
        }

        reverse(topo.begin(), topo.end());

        const int INF = 1e9;

        vector<int> dist(n,INF);

        dist[src]=0;

        for(int u:topo)
        {
            if(dist[u]==INF)
                continue;

            for(auto &[v,w]:adj[u])
            {
                dist[v]=min(
                    dist[v],
                    dist[u]+w
                );
            }
        }

        return dist;
}

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

    // DAGShortestPath obj;

    vector<int> dist = shortestPath(n,adj,0);

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

