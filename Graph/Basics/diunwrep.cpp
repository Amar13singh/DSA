#include <bits/stdc++.h>
using namespace std;


//for Directed Graph.....
class DirectedGraph {
    int n;
    vector<vector<int>> adj;

public:
    DirectedGraph(int nodes) {
        n = nodes;
        adj.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
    }

    void removeEdge(int u, int v) {
        adj[u][v] = 0;
    }

    bool hasEdge(int u, int v) {
        return adj[u][v];
    }

    void print() {
        for (auto &row : adj) {
            for (int x : row) cout << x << " ";
            cout << "\n";
        }
    }
};

int main() {
    DirectedGraph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.print();
}