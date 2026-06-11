#include<bits/stdc++.h>
using namespace std;

//using bfs for solving this question...
int orangeRot(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    
    queue<pair<int,int>> q;
    int fresh = 0;

    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(mat[i][j]==2){
                q.push({i,j});
            }
            if(mat[i][j]==1) fresh++;
        }
    }

    if(fresh==0) return 0;
    int minutes = 0;

    int dr[]={-1,+1,0,0};
    int dc[]={0,0,-1,+1};

    while(!q.empty()){
        int sz = q.size();
        bool rotted = false;

        while(sz--){
            auto[r,c]= q.front();
            q.pop();

            for(int i = 0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
            
            if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc] == 1){
                    mat[nr][nc] = 2;
                    fresh--;
                    q.push({nr,nc});
                    rotted = true;
            }
        }
    }
    if(rotted) minutes++;

}
return fresh?-1:minutes;


}

int main() {

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << "Answer = "
        << orangeRot(grid)
        << endl;

    return 0;
}