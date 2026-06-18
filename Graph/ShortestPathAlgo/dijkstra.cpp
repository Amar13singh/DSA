#include<bits/stdc++.h>
using namespace std;


vector<int> dijkstra(vector<vector<pair<int,int>>>& adj,int src){
    int V = adj.size();
    vector<int> dist(V, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;

    pq.push({0, src});

    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        // stale entry
        if(d > dist[u])
            continue;

        for(auto &[v, w] : adj[u])
        {
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


int main(){
    vector<vector<pair<int,int>>> adj(11);

adj[0] = {{1,4},{2,1},{3,10}};

adj[1] = {{0,4},{4,2}};

adj[2] = {{0,1},{3,2},{5,5}};

adj[3] = {{0,10},{2,2},{4,1},{6,1}};

adj[4] = {{1,2},{3,1},{6,3}};

adj[5] = {{2,5},{6,2}};

adj[6] = {{3,1},{4,3},{5,2}};

adj[7] = {{8,1}};

adj[8] = {{7,1}};

adj[9] = {};

adj[10] = {{10,7}};

vector<int> ans = dijkstra(adj,0);

for(int i = 0;i<ans.size();i++){
    cout<<"Shortest Distance B/W 0 and "<< i <<" is: ";
    ans[i]==INT_MAX?cout<<"unrechable"<<endl :cout<<ans[i]<<endl;
}


}