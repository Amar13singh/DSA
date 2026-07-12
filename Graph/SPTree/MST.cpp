#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// ============================================================
// DSU
// ============================================================

class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV)
            return false;

        if (size[rootU] < size[rootV])
            swap(rootU, rootV);

        parent[rootV] = rootU;
        size[rootU] += size[rootV];

        return true;
    }
};


// ============================================================
// KRUSKAL
// ============================================================

struct Edge {
    int u;
    int v;
    int wt;
};

long long kruskalMST(int n, vector<Edge> edges) {

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.wt < b.wt;
         });

    DSU dsu(n);

    long long mstCost = 0;
    int edgesUsed = 0;

    cout << "\nKruskal MST Edges:\n";

    for (const Edge& edge : edges) {

        if (dsu.unite(edge.u, edge.v)) {

            cout << edge.u
                 << " -- "
                 << edge.v
                 << "   weight = "
                 << edge.wt
                 << '\n';

            mstCost += edge.wt;
            edgesUsed++;

            if (edgesUsed == n - 1)
                break;
        }
    }

    if (edgesUsed != n - 1)
        return -1;

    return mstCost;
}


// ============================================================
// PRIM
// ============================================================

long long primMST(
    int n,
    vector<vector<pair<int, int>>>& adj
) {

    // {weight, node, parent}

    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    vector<bool> inMST(n, false);

    pq.push({0, 0, -1});

    long long mstCost = 0;
    int verticesUsed = 0;

    cout << "\nPrim MST Edges:\n";

    while (!pq.empty()) {

        auto current = pq.top();
        pq.pop();

        int wt = current[0];
        int node = current[1];
        int parent = current[2];

        if (inMST[node])
            continue;

        inMST[node] = true;

        mstCost += wt;
        verticesUsed++;

        if (parent != -1) {
            cout << parent
                    << " -- "
                    << node
                    << "   weight = "
                    << wt
                    << '\n';
        }

        for (auto [nbr, edgeWt] : adj[node]) {

            if (!inMST[nbr]) {
                pq.push({
                    edgeWt,
                    nbr,
                    node
                });
            }
        }
    }

    if (verticesUsed != n)
        return -1;

    return mstCost;
}


// ============================================================
// DRIVER
// ============================================================

int main() {

    int n = 8;

    /*
                      4
              0 ------------- 1
              | \             /|
             8|  \3         2/ |7
              |   \         /  |
              2----6-------3   4
              |    |5      |   |
             9|    |       |6  |1
              |    |       |   |
              5----7-------4---+
                  2       10

        Vertices:

        0, 1, 2, 3, 4, 5, 6, 7

        Complex cases covered:

        - Multiple cycles
        - Competing cheap edges
        - Heavy redundant edges
        - Multiple possible paths
        - DSU cycle rejection
        - Prim stale heap entries
    */


    vector<Edge> edges = {

        {0, 1, 4},
        {0, 2, 8},
        {0, 6, 3},

        {1, 3, 2},
        {1, 4, 7},

        {2, 6, 6},
        {2, 5, 9},

        {3, 6, 4},
        {3, 4, 6},

        {4, 7, 10},

        {5, 7, 2},

        {6, 7, 5}
    };


    // --------------------------------------------------------
    // Build adjacency list for Prim
    // --------------------------------------------------------

    vector<vector<pair<int, int>>> adj(n);

    for (const Edge& edge : edges) {

        adj[edge.u].push_back({
            edge.v,
            edge.wt
        });

        adj[edge.v].push_back({
            edge.u,
            edge.wt
        });
    }


    // --------------------------------------------------------
    // Run Prim
    // --------------------------------------------------------

    long long primCost = primMST(n, adj);

    cout << "\nPrim MST Cost = "<< primCost<< '\n';


    // --------------------------------------------------------
    // Run Kruskal
    // --------------------------------------------------------

    long long kruskalCost = kruskalMST(n, edges);

    cout << "\nKruskal MST Cost = "<< kruskalCost<< '\n';


    // --------------------------------------------------------
    // Verify
    // --------------------------------------------------------

    cout << "\nVerification:\n";

    if (primCost == kruskalCost)
        cout << "Both algorithms produced same MST cost.\n";
    else
        cout << "ERROR: MST costs differ.\n";


    return 0;
}