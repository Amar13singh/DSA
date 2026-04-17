#include<bits/stdc++.h>
using namespace std;


class GraphString {
    unordered_map<string, vector<string>> adj;

public:
    void addEdge(string u, string v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};


