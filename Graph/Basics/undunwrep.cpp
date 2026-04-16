#include <bits/stdc++.h>
using namespace std;

class UndirectedGraph { //main class ..
    int n;
    vector<vector<int>> adj;

public:
    UndirectedGraph(int nodes) { //constructor ..
        n = nodes;
        adj.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= n || v >= n) {
            throw out_of_range("Invalid node index");
        }

        adj[u][v] = 1;
        adj[v][u] = 1; // symmetry
    }

    void removeEdge(int u, int v) {
        adj[u][v] = 0;
        adj[v][u] = 0;
    }

    bool hasEdge(int u, int v) {
        return adj[u][v] == 1;
    }

    void print() {
        for (auto &row : adj) {
            for (int x : row) cout << x << " ";
            cout << "\n";
        }
    }
};

int main() {
    UndirectedGraph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.print();
}