#include<bits/stdc++.h>
using namespace std;


class DirectedGraph {
    int n;
    vector<vector<int>> adj;

public:
    DirectedGraph(int nodes) {
        n = nodes;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // one direction only
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
    DirectedGraph g(5);
    g.addEdge(1, 2);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.print();
}