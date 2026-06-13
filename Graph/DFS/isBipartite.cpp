#include<bits/stdc++.h>
using namespace std;


bool dfs(int node,vector<vector<int>>& graph,vector<int>& col,int clr){
    col[node] = clr;

    for(int x:graph[node]){
        if(col[x]==-1){
            if(!dfs(x,graph,col,1-clr)) return false;
        }
        else if(col[x]==col[node]) return false;
    }
    return true;
}



bool isBipartite(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> col(n,-1);
    for(int i=0;i<n;i++){
        if(col[i]==-1){
            if(!dfs(i,graph,col,0)) return false;

        }
    }
    return true;
}

//Driver code...

int main() {

    // Test 1: Single Node
    vector<vector<int>> g1 = {
        {}
    };

    cout<<"Single Node:"<<isBipartite(g1)<<endl;

    // Test 2: No Edges
    vector<vector<int>> g2 = {
        {},
        {},
        {},
        {}
    };

    cout<<"No Edges:"<<isBipartite(g2)<<endl;

    // Test 3: Simple Bipartite
    vector<vector<int>> g3 = {
        {1},
        {0}
    };

    cout<<"Simple Bipartite:"<<isBipartite(g3)<<endl;


    // Test 4: Square Cycle (Even Cycle)
    vector<vector<int>> g4 = {
        {1,3},
        {0,2},
        {1,3},
        {0,2}
    };

    cout<<"Square/Even Cycle:"<<isBipartite(g4)<<endl;


    // Test 5: Triangle (Odd Cycle)
    vector<vector<int>> g5 = {
        {1,2},
        {0,2},
        {0,1}
    };

    cout<<"Triangle/odd Cycle:"<<isBipartite(g5)<<endl;


    // Test 6: Self Loop
    vector<vector<int>> g6 = {
        {0}
    };

    cout<<"Self loop:"<<isBipartite(g6)<<endl;


    // Test 7: Disconnected Graph (All Bipartite)
    vector<vector<int>> g7 = {
        {1},
        {0},
        {3},
        {2}
    };

    // runTest(g7, "Test 7: Disconnected Bipartite");
        cout<<"Disconnected:"<<isBipartite(g7)<<endl;



    // Test 8: One Component Not Bipartite
    vector<vector<int>> g8 = {
        {1},
        {0},

        {3,4},
        {2,4},
        {2,3}
    };

    // runTest(g8, "Test 8: One Bad Component");
        cout<<"test case:"<<isBipartite(g8)<<endl;



    // Test 9: Line Graph
    vector<vector<int>> g9 = {
        {1},
        {0,2},
        {1,3},
        {2,4},
        {3}
    };

    // runTest(g9, "Test 9: Line Graph");
        cout<<"Line Graph:"<<isBipartite(g9)<<endl;



    // Test 10: Complete Bipartite K(3,3)
    vector<vector<int>> g10 = {
        {3,4,5},
        {3,4,5},
        {3,4,5},

        {0,1,2},
        {0,1,2},
        {0,1,2}
    };

    // runTest(g10, "Test 10: Complete Bipartite");
        cout<<"Complete bipartite:";
        isBipartite(g10)?cout<<"Yes"<<endl:cout<<"No"<<endl;


    return 0;
}