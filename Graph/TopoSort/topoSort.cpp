//Implementing topological sorting in cpp.....

#include<bits/stdc++.h>
using namespace std;

//using dfs... Recursive way...


void dfs(int node,vector<vector<int>>& mat,vector<int>& vis,stack<int>& st){
    vis[node]=1;
    for(int x:mat[node]){
        if(!vis[x]){
            dfs(x,mat,vis,st);
        }
    }
    st.push(node);
}



vector<int> topoSort(vector<vector<int>>& mat){
    int n= mat.size();

    vector<int> vis(n,0);
    vector<int> ans;
    stack<int>st;

    for(int i = 0;i<n;i++){
        if(!vis[i]){
            dfs(i,mat,vis,st);
        }
    }
//pushing nodes in array/vector..in reverse order...
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
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


vector<vector<int>> adj2 = {
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