#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int x){
        val = x;
    }
};


vector<tuple<int,int,int>>nodes;

void dfs(Node* root,int row ,int col){
    if(root==nullptr) return;

    nodes.push_back({col,row,root->val});
    dfs(root->left,row+1,col-1);
    dfs(root->right,row+1,col+1);
}

vector<vector<int>>verticalTraversal(Node* root){

    dfs(root,0,0);

    sort(nodes.begin(),nodes.end());
    
    int precol = INT_MIN;
    vector<vector<int>>ans;
    for(auto&[col,row,val]:nodes){
        if(precol!=col){
            ans.push_back({});
            precol = col;
        }
        ans.back().push_back(val);
    }
    return ans;

}


int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);

    root->right->left = new Node(15);
    root->right->right = new Node(7);
    
    vector<vector<int>>ans = verticalTraversal(root);

    cout<<"vertical order is: [ ";

    for(auto row:ans){
        cout<<"[ ";
        for(int x:row){
            cout<<x<<" ";
        }
        cout<<"] ";
    }
    cout<<"]";


}


// complexity: T(n):O(nlogn) ,   S(n):O(n)
// dfs:O(n), sorting:O(nlogn)