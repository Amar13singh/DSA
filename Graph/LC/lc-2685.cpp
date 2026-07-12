//count the number of  complete components..

#include<bits/stdc++.h>
using namespace std;


int countCmComp(int n,vector<vector<int>>&edges){
    vector<vector<int>>adj(n);
    
    for(auto &edge:edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // queue<int>q;
    vector<int>vis(n,0);
    int ans = 0;
    
    for(int i=0;i<n;i++){
        
        if(!vis[i]){
            
            queue<int>q;
            q.push(i);
            vis[i]=1;

            long long nodes = 0;
            long long degSum = 0;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                nodes++;
                degSum += adj[node].size();

                for(int x:adj[node]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x]=1;
                    }
                }
            }
            if (degSum == nodes * (nodes - 1)) {
                    ans++;
                }
        }

    }
    return ans;
}


int main() {

    int n = 15;

    vector<vector<int>> edges = {

        // Component 1: Complete K3
        {0, 1},
        {0, 2},
        {1, 2},

        // Component 2: Complete K2
        {3, 4},

        // Component 3:
        // Node 5 is isolated

        // Component 4: NOT complete
        {6, 7},
        {6, 8},
        {7, 8},
        {8, 9},

        // Component 5: Complete K4
        {10, 11},
        {10, 12},
        {10, 13},
        {11, 12},
        {11, 13},
        {12, 13}

        // Component 6:
        // Node 14 is isolated
    };


    // Solution obj;

    int result = countCmComp(n, edges);

    cout << "Number of complete components: "
            << result << endl;

    return 0;
}
    