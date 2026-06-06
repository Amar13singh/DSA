#include<bits/stdc++.h>
using namespace std;

bool topoSort(vector<vector<int>>& mat){
    int n= mat.size();
    vector<int> indeg(n,0);
    for(auto x:mat){
        for(int y:x) indeg[y]++;
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0) q.push(i);
    }
    int count = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;

        for(int x:mat[node]){
            indeg[x]--;
            if(indeg[x]==0) q.push(x);
        }

    }
    return count <n;
}


int main(){
    vector<vector<int>> adj =
    {
        {1,3},   // 0
        {0,2},   // 1
        {1,3},   // 2
        {0,2}    // 3
    };

    vector<vector<int>> adj1 =
{
    {1},        // 0
    {0,2},      // 1
    {1},        // 2

    {4,5},      // 3
    {3,5},      // 4
    {3,4}       // 5
};

    cout << (topoSort(adj1) ? "Cycle Found" : "No Cycle");

    return 0;


}

// Time Complexity:O(E+V)
// Space Complexity:O(V)