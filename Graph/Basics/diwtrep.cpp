#include <bits/stdc++.h>
using namespace std;

class WeightedDirectedGraph {
    int n;
    const int INF = 1e9;
    vector<vector<int>> adj;

public:
    WeightedDirectedGraph(int nodes) {
        n = nodes;
        adj.assign(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
            adj[i][i] = 0;
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
    }

    void print() {
        for (auto &row : adj) {
            for (int x : row) {
                if (x == INF) cout << "INF ";
                else cout << x << "   ";
            }
            cout << "\n";
        }
    }
};

int main(){
    WeightedDirectedGraph g(5);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, -1);
    g.addEdge(1, 3, 4);
    g.addEdge(3, 4, 2);

    g.print();
}