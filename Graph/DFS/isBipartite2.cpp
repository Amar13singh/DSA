#include <bits/stdc++.h>
using namespace std;


//bfs soln...
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1); // -1=uncolored

        for(int start = 0; start < n; start++) {

            if(color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                for(int nei : graph[node]) {

                    if(color[nei] == -1) {
                        color[nei] = 1 - color[node];
                        q.push(nei);
                    }
                    else if(color[nei] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

void runTest(vector<vector<int>> graph, string name) {

    Solution obj;

    cout << "=========================\n";
    cout << name << "\n";

    bool ans = obj.isBipartite(graph);

    cout << "Answer: ";

    if(ans)
        cout << "Bipartite\n";
    else
        cout << "Not Bipartite\n";

    cout << "=========================\n\n";
}

int main() {

    // Test 1: Single Node
    vector<vector<int>> g1 = {
        {}
    };

    runTest(g1, "Test 1: Single Node");


    // Test 2: No Edges
    vector<vector<int>> g2 = {
        {},
        {},
        {},
        {}
    };

    runTest(g2, "Test 2: No Edges");


    // Test 3: Simple Bipartite
    vector<vector<int>> g3 = {
        {1},
        {0}
    };

    runTest(g3, "Test 3: Two Nodes");


    // Test 4: Square Cycle (Even Cycle)
    vector<vector<int>> g4 = {
        {1,3},
        {0,2},
        {1,3},
        {0,2}
    };

    runTest(g4, "Test 4: Even Cycle");


    // Test 5: Triangle (Odd Cycle)
    vector<vector<int>> g5 = {
        {1,2},
        {0,2},
        {0,1}
    };

    runTest(g5, "Test 5: Triangle");


    // Test 6: Self Loop
    vector<vector<int>> g6 = {
        {0}
    };

    runTest(g6, "Test 6: Self Loop");


    // Test 7: Disconnected Graph (All Bipartite)
    vector<vector<int>> g7 = {
        {1},
        {0},
        {3},
        {2}
    };

    runTest(g7, "Test 7: Disconnected Bipartite");


    // Test 8: One Component Not Bipartite
    vector<vector<int>> g8 = {
        {1},
        {0},

        {3,4},
        {2,4},
        {2,3}
    };

    runTest(g8, "Test 8: One Bad Component");


    // Test 9: Line Graph
    vector<vector<int>> g9 = {
        {1},
        {0,2},
        {1,3},
        {2,4},
        {3}
    };

    runTest(g9, "Test 9: Line Graph");


    // Test 10: Complete Bipartite K(3,3)
    vector<vector<int>> g10 = {
        {3,4,5},
        {3,4,5},
        {3,4,5},

        {0,1,2},
        {0,1,2},
        {0,1,2}
    };

    runTest(g10, "Test 10: Complete Bipartite");


    return 0;
}