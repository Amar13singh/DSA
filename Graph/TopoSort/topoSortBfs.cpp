//Topological sorting using bfs/kahn's algo....

#include<bits/stdc++.h>
using namespace std;

vector<int>topoSort(vector<vector<int>>&mat){
    int n= mat.size();
    vector<int>indeg(n,0);
    queue<int>q;
    vector<int>ans;

    for(auto x:mat){
        for(int y:x){
            indeg[y]++;
        }
    }

    for(int i = 0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);
        for(int x:mat[node]){
            indeg[x]--;                //very imp line..

            if(indeg[x]==0){
                q.push(x);
            }
        }
    }

    //cycle detection....
    if(ans.size()!=n){
        cout << "Cycle exists. Topological Sort not possible.\n";

        return {};
    }
    return ans;
}

int main() {

vector<vector<int>> adj = {
    {},      // 0
    {},      // 1
    {3},     // 2 -> 3
    {1},     // 3 -> 1
    {0,1},   // 4 -> 0,1
    {0,2}    // 5 -> 0,2
};


vector<vector<int>> adj1 = {
    {1},    // 0 -> 1
    {},     // 1
    {3},    // 2 -> 3
    {},     // 3
    {5},    // 4 -> 5
    {},     // 5
    {}      // 6 isolated
};


vector<vector<int>> adj2 = {  //contain cycle...
    {1},    // 0 -> 1
    {2},    // 1 -> 2
    {0,3},  // 2 -> 0,3
    {}      // 3
};


    vector<int> ans = topoSort(adj);

    cout << "Topological Order: ";

    for(int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}