#include<bits/stdc++.h>
using namespace std;

int main() {

    int n = 4;

    vector<vector<int>> adj(n);   //Adjacency List.....

    adj[0] = {1,2};
    adj[1] = {3};
    adj[2] = {3};

    vector<int> indegree(n,0);

    for(int u=0; u<n; u++){
        for(int v : adj[u]){
            indegree[v]++;
        }
    }

    for(int u=0; u<n; u++){

        int outdegree = adj[u].size();

        cout << "Node " << u
                << " indegree = "
                << indegree[u]
                << " outdegree = "
                << outdegree << "\n";
    }
}

// Time Complexity:O(V+E)