#include<bits/stdc++.h>
using namespace std;

void bellmanFord(int v,vector<vector<int>>& graph,int src){
    vector<int> dist(v,INT_MAX);
    vector<int> parent(v,-1);
    // vector<int> path;

    dist[src]=0;
    for(int i = 0;i<v-1;i++){
        for(auto &e:graph){
            int u = e[0];
            int v1 = e[1];
            int w = e[2];

            if(dist[u]!=INT_MAX && dist[u]+w < dist[v1]){
                dist[v1] = dist[u]+w;
                parent[v1] = u;
            }
        }
    }
    //Checking Negative Cycle...
    for(auto &e:graph){
        if(dist[e[0]]!=INT_MAX && dist[e[0]]+e[2] < dist[e[1]]){
            cout<<"Negative Cycle\n";
            return;
        }
    }
    //tracing paths for every node..
    for(int i=0;i<v;i++){

        cout<<"Source = "<<src
            <<" Destination = "<<i<<"\n";

        if(dist[i] == INT_MAX)
        {
            cout<<"Distance = INF\n";
            cout<<"Path : No Path\n\n";
            continue;
        }

        vector<int>path;

        for(int curr = i;curr != -1;curr=parent[curr]){
            path.push_back(curr);
        }
        reverse(path.begin(),path.end());

        // cout<<"Starting node: "<<src<<" and Destination node "<<i;

        cout << "Distance = "
                << dist[i]
                << "\n";

        cout << "Path : ";
    
        for(int node : path)
            cout << node << " ";
    
        cout << "\n\n";
    }

}
int main(){
    int V = 5;

    vector<vector<int>> edges = {
        {0,1,4},
        {0,2,5},
        {1,2,-2},
        {2,3,3},
        {3,4,2}
    };

    int src = 0;

    bellmanFord( V,edges, src);

}