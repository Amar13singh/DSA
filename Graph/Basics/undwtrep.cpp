#include <bits/stdc++.h>
using namespace std;


//Weighted Undirected Graph............
class WeightedUndirectedGraph {
    int n;
    const int INF = 1e9;
    vector<vector<int>> adj;

public:
    WeightedUndirectedGraph(int nodes) {
        n = nodes;
        adj.assign(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
            adj[i][i] = 0;
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    void print() {
        for (auto &row : adj) {
            for (int x : row) {
                if (x == INF) cout << "?  ";
                else cout << x << "   ";
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