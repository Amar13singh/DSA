#include<bits/stdc++.h>
using namespace std;



vector<int> topoSort(vector<vector<int>>& adj){
    int n= adj.size();
    vector<int> vis(n,0);

    vector<int> topo;

    for(int start=0; start<n; start++)
    {
        if(vis[start]) continue;

        stack<pair<int,bool>> st;

        st.push({start,false});

        while(!st.empty())
        {
            auto [node, processed] = st.top();
            st.pop();

            if(processed)
            {
                topo.push_back(node);
                continue;
            }

            if(vis[node])
                continue;

            vis[node]=1;

            st.push({node,true});

            for(int i=adj[node].size()-1;i>=0;i--)
            {
                int nbr=adj[node][i];

                if(!vis[nbr])
                    st.push({nbr,false});
            }
        }
    }

    reverse(topo.begin(), topo.end());

    return topo;
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