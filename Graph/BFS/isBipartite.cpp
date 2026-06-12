#include<bits/stdc++.h>
using namespace std;



bool isBipartite(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> col(n,-1);
    queue<int> q;

    for(int i = 0;i<n;i++){

        if(col[i]!=-1) continue;
        q.push(i);
        col[i]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int x:graph[node]){

                if(col[x]==-1){
                    col[x] = 1-col[node];
                    q.push(x);
                }
                else if(col[x]== col[node]) return false;
            }
        }

    }
    return true;
}


int main(){
    vector<vector<int>> mat ={
        {1,2,3},
        {0,2},
        {0,1,3},
        {0,2}
    };

    vector<vector<int>> mat1 ={
        {1,3},
        {0,2},
        {1,3},
        {0,2}
    };
    isBipartite(mat1)?cout<<"Yes":cout<<"No";
}