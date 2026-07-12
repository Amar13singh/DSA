#include <bits/stdc++.h>
using namespace std;

//Heap based Prim Algo...
int prim(int V, vector<vector<pair<int,int>>>& adj){
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> vis(V,0);

    pq.push({0,0});

    int mstCost = 0;
    int Vsed =0;

    while(!pq.empty())
    {
        auto [wt,node] = pq.top();
        pq.pop();

        if(vis[node])
            continue;

        vis[node] = 1;
        mstCost += wt;
        Vsed++;

        for(auto &[nbr,edgeWt] : adj[node])
        {
            if(!vis[nbr])
                pq.push({edgeWt,nbr});
        }
    }
    if(Vsed!=V) return -1;

    return mstCost;
}

int main()
{
    int V = 6;

    vector<vector<pair<int,int>>> adj(V);

    auto addEdge = [&](int u,int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    };

    addEdge(0,1,4);
    addEdge(0,2,8);
    addEdge(0,3,2);

    addEdge(1,3,6);

    addEdge(2,3,3);
    addEdge(2,4,5);
    addEdge(2,5,7);

    addEdge(3,5,1);

    addEdge(4,5,2);

    cout << "MST Cost = "<< prim(V,adj)<< "\n";

    return 0;
}

// Complexity:
    // Time:O(ElogV)
    // Space:O(V)

