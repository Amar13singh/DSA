#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> arr,int start){
    int n= arr.size();
    vector<bool> vis(n,false);
    queue<int> q;
    vector<int>ans;

    vis[start]=true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int x:arr[node]){
            if(!vis[x]){
                vis[x]= true;
                q.push(x);
            }
        }

    }
    return ans;

}


int main(){
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<int> arr = bfs(adj,0);
    for(int x:arr) cout<<x<<" ";
}