#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Classical Prim: O(V^2)

int primMST(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    key[0] = 0;

    for (int count = 0; count < n; count++) {

        int u = -1;

        for (int v = 0; v < n; v++) {
            if (!inMST[v] &&
                (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        if (u == -1 || key[u] == INT_MAX)
            return -1;

        inMST[u] = true;

        for (int v = 0; v < n; v++) {

            if (graph[u][v] != 0 &&
                !inMST[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int cost = 0;

    for (int i = 0; i < n; i++)
        cost += key[i];

    return cost;
}

int main(){

}