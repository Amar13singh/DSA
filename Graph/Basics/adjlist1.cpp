#include <bits/stdc++.h>
using namespace std;

class UndirectedGraph {
    int n;
    vector<vector<int>> adj;

public:
    UndirectedGraph(int nodes) {
        n = nodes;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        // validation (important edge case)
        if (u < 0 || v < 0 || u >= n || v >= n)
            throw out_of_range("Invalid node");

        adj[u].push_back(v);
        adj[v].push_back(u); // symmetry
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int v : adj[i]) cout << v << " ";
            cout << "\n";
        }
    }
};
int main(){
    UndirectedGraph g(5);
    g.addEdge();
}