#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(int x)
    {
        val = x;
        left = right = nullptr;
    }
};



//assign cols..
//exactly opposite---- Last node in every column.

vector<int> bottomView(TreeNode* root)
{
    vector<int> ans;

    if(root==nullptr)
        return ans;

    map<int,int> mp;

    queue<pair<TreeNode*,int>> q;

    q.push({root,0});

    while(!q.empty())
    {
        auto [nd,cl]=q.front();
        q.pop();

        TreeNode* node=nd;
        int col=cl;

        mp[col]=node->val;

        if(node->left)
            q.push({node->left,col-1});

        if(node->right)
            q.push({node->right,col+1});
    }

    for(auto x:mp)
        ans.push_back(x.second);

    return ans;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int>arr = bottomView(root);
    cout<<"bottom view: ";
    for(int x:arr) cout<<x<<" ";
}