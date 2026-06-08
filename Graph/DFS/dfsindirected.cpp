#include<bits/stdc++.h>
using namespace std;

//dfs through adjacency matrix...
//Recursive method...

//mainn code...
void dfs(vector<vector<int>>& mat,int start,vector<int>& ans,vector<int>&vis){
    int n= mat.size();
    vis[start] = 1;
    ans.push_back(start);
    for(int i = 0;i<n;i++){
        if(mat[start][i]==1 && !vis[i]){
            dfs(mat,i,ans,vis);
        }
    }
}


vector<int> dfstr(vector<vector<int>>& mat,int start){
    int n = mat.size();

    vector<int> vis(n,0);
    vector<int> ans;
    dfs(mat,start,ans,vis);
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
    vector<int> arr = dfstr(mat,3);
    cout<<"Dfs of given graph is :";
    for(int x:arr) cout<<x<<" ";
}