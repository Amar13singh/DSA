#include<bits/stdc++.h>
using namespace std;

 int minOperations(vector<vector<int>>& grid, int z) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;

        //flattening..
        for(auto &row:grid){
            for(int col:row) arr.push_back(col);
        }
        sort(arr.begin(),arr.end());

        int val = arr.size()/2;
        int key = arr[val];
        int ans = 0;

        // Feasibility check
        int mod = arr[0] % z;
        for (int x : arr) {
            if (x % z != mod) return -1;
        }


        
        for(int x:arr){
            ans+=abs(key-x)/z;
        }
            
        return ans;

    }



    int main(){
        vector<vector<int>> arr = {{1,5},{2,3}};
        int z = 1;
        cout<<"ans is:";
        cout<<minOperations(arr,z);
    }