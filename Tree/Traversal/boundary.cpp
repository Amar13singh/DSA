#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
    }
};

void leftBoundary(TreeNode* root,vector<int>& ans){
    TreeNode* curr = root->left;  //bcz we cant take root here...

    while(curr){
        if(!(curr->left==nullptr && curr->right==nullptr)){
            ans.push_back(curr->val);
        }

        if(curr->left) curr = curr->left;
        else curr= curr->right;
    }
}


void rightBoundary(TreeNode* root,vector<int>& ans){
    TreeNode* cur = root;
    vector<int> temp;
    while(cur){
        if(!(cur->left==nullptr && cur->right==nullptr)) temp.push_back(cur->val);

        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    reverse(temp.begin(),temp.end());
    
    for (int x : temp)
        ans.push_back(x);

}


void addLeaves(TreeNode* root, vector<int>& ans) {

    if (!root)
        return;

    if (!root->left && !root->right) {
        ans.push_back(root->val);
        return;
    }

    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}


vector<int> boundary(TreeNode* root){
    vector<int>ans;
    if(!root) return ans;

    // add root only if not leaf
    if (root->left || root->right)
        ans.push_back(root->val);

    leftBoundary(root, ans);

    addLeaves(root, ans);

    rightBoundary(root, ans);

    return ans;
}


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int>arr = boundary(root);

    cout<<"boundary traversal is :";
    for(int x:arr)cout <<x<<" ";
}
