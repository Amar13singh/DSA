#include<bits/stdc++.h>
using namespace std;



// Serialization means converting a tree into a 
// linear representation (string/vector) so it can be:

// Stored in a file
// Sent over a network
// Saved in a database
// Reconstructed later


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};


void serialize(TreeNode* root, string &ans)
{
    if(root == nullptr)
    {
        ans += "N ";
        return;
    }

    ans += to_string(root->val) + " ";

    serialize(root->left, ans);

    serialize(root->right, ans);
}



int main(){
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    string ans = "";
    serialize(root,ans);

    cout<<ans;

}


