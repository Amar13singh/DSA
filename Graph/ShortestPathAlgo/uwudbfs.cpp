#include<bits/stdc++.h>
using namespace std;

//implementing shortest path Algo by Bfs...

vector<int> shortestPath(vector<vector<int>>& mat,int src){
    int n= mat.size();
    vector<int> dist(n,-1);
    // vector<int> ans;
    queue<int> q;

    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int x:mat[node]){
            if(dist[x]==-1){
                dist[x] = dist[node]+1;
                q.push(x);
            }
        }
    }
    return dist;
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
vector<int>ans = shortestPath(adj,0);

for(int i = 0;i<ans.size();i++){
    cout<<"Shortest Distance B/W 0 and "<< i <<"is: "<<ans[i]<<endl;
}

}