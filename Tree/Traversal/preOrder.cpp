#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;

    }
};

//or..
// struct TreeNode{
//     int val;

//     TreeNode* left;

//     TreeNode* right;

//     TreeNode(int x)
//     {
//         val=x;
//         left=right=nullptr;
//     }
// };



void preorder(TreeNode* root){
    if(root==nullptr) return;
    
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}




int main(){
    TreeNode* root;
    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout<<"Preorder: ";
    preorder(root);

}