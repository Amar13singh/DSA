#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(
                        vector<vector<int>>& adj,
                        int src,
                        int dest){
                            int V = adj.size();
    vector<int> dist(V,-1);
    vector<int> parent(V,-1);

    queue<int> q;

    q.push(src);
    dist[src] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int nei: adj[node])
        {
            if(dist[nei] == -1)
            {
                dist[nei] = dist[node] + 1;
                parent[nei] = node;
                q.push(nei);
            }
        }
    }

    if(dist[dest] == -1)
        return {};

    vector<int> path;

    int cur = dest;

    while(cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    return path;
}


int main(){
    vector<vector<int>> adj = {
    {1,2},          //0
    {0,2,3,4},      //1
    {0,1,5,6},      //2
    {1,7},          //3
    {1,5,8},        //4
    {2,4},          //5
    {2,9},          //6
    {3,8},          //7
    {4,7,9},        //8
    {6,8},          //9
    {11},           //10
    {10},           //11
    {},             //12 isolated
    {13}            //13 self-loop
};
vector<int>ans = shortestPath(adj,0,8);

cout<<"Shortest distance path: ";
for(int i = 0;i<ans.size();i++){
    cout<<ans[i]<<"-->";
}

}