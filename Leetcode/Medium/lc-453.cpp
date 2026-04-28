#include<bits/stdc++.h>
using namespace std;


    int minMoves(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int moves = 0;
        
        for (int x : nums) {
            moves += (x - minVal);
        }
        
        return moves;
    }


    int main(){
        vector<int> arr = {1,2,3};
        cout<<"Ans is:";
        cout<<minMoves(arr);
    }