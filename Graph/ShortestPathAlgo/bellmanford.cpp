#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

vector<int> bellmanFord(vector<Edge>& edges,int src){
    int n= edges.size();
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;

    for(int i=0;i<n;i++){
        bool updated = false;

    for(auto &e:edges){
        int u = e.u;
        int v = e.v;
        int w = e.w;

        if(dist[u]!=INT_MAX && dist[u]+w <dist[v]){
            dist[v] = dist[u]+w;
            updated = true;
        }
    
    }

    //early stoppping optimization...
    if(!updated) break;
    }

    //Negative cycle detection...
    for(auto&e:edges){
        int u = e.u;
        int v = e.v;
        int w = e.w;

        if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
            cout<<"Negative Ccycle detected\n";
            return {};
        }
    }
    return dist;

}

int main() {

    int V = 5;

    vector<Edge> edges = {
        {0,1,4},
        {0,2,5},
        {1,2,-2},
        {2,3,3},
        {3,4,2}
    };

    int src = 0;

    vector<int> dist = bellmanFord(edges, src);

    if(!dist.empty()) {

        cout << "Shortest Distances From 0:\n";

        for(int i = 0; i < V; i++) {

            if(dist[i] == INT_MAX)
                cout << i << " -> INF\n";
            else
                cout << i << " -> " << dist[i] << "\n";
        }
    }
}