//Bfs through adjacency matrix...

#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &mat,int start){
    int n = mat.size();
    vector<int> vis(n,0);
    vector<int> ans;

    queue<int> q;
    q.push(start);
    vis[start]=1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int i=0;i<n;i++){
            if(mat[node][i]==1 && !vis[i]){ //main logic.....
                q.push(i);
                vis[i]=1;
            }
        }
    }
    return ans;


}

int main(){
    vector<vector<int>> mat = {
 //0 1 2 3 4 5 6
  {0,1,1,0,0,0,0}, // 0
  {1,0,0,1,1,0,0}, // 1
  {1,0,0,0,0,1,0}, // 2
  {0,1,0,0,0,0,0}, // 3
  {0,1,0,0,0,0,1}, // 4
  {0,0,1,0,0,0,1}, // 5
  {0,0,0,0,1,1,0}  // 6
};
    vector<int> arr = bfs(mat,3);
    cout<<"Bfs of given graph is :";
    for(int x:arr) cout<<x<<" ";
}
