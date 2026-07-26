#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

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

// Inorder Traversal
void inorder(TreeNode* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(TreeNode* root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(TreeNode* root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Level Order Traversal
void levelOrder(TreeNode* root)
{
    if (root == nullptr)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}

// Height
int height(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

// Size
int size(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    return 1 + size(root->left) + size(root->right);
}

// Leaf Count
int leafCount(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return leafCount(root->left) + leafCount(root->right);
}

// Delete Tree
void deleteTree(TreeNode* root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main()
{
    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;

    cout << "Height = " << height(root) << endl;

    cout << "Size = " << size(root) << endl;

    cout << "Leaf Count = " << leafCount(root) << endl;

    deleteTree(root);
    root = nullptr;

    return 0;
}