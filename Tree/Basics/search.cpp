#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};


TreeNode* search(TreeNode* root,int target)
{
    if(root==nullptr)
        return nullptr;

    if(root->val==target)
        return root;

    TreeNode* left=search(root->left,target);

    if(left)
        return left;

    return search(root->right,target);
}

//complexity: T(n):O(n) S(n):
