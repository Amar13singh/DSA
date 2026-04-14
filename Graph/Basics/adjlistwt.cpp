#include<bits/stdc++.h>
using namespace std;


class WeightedUndirectedGraph {
    int n;
    vector<vector<pair<int,int>>> adj;

public:
    WeightedUndirectedGraph(int nodes) {
        n = nodes;
        adj.resize(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (auto [v, w] : adj[i]) {
                cout << "(" << v << "," << w << ") ";
            }
            cout << "\n";
        }
    }
};

int main(){
    WeightedUndirectedGraph g(5);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, -1);
    g.addEdge(1, 3, 4);
    g.addEdge(3, 4, 2);

    g.print();
}