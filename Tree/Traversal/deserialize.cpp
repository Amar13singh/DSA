#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = right = nullptr;
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


vector<string> split(string s)
{
    vector<string> arr;

    stringstream ss(s);

    string x;

    while(ss >> x)
        arr.push_back(x);

    return arr;
}

TreeNode* build(vector<string> &arr, int &idx)
{
    if(arr[idx] == "N")
    {
        idx++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(arr[idx]));

    idx++;

    root->left = build(arr, idx);

    root->right = build(arr, idx);

    return root;
}

TreeNode* deserialize(string s)
{
    vector<string> arr = split(s);

    int idx = 0;

    return build(arr, idx);
}

void preorder(TreeNode* root)
{
    if(root == nullptr)
        return;

    cout << root->val << " ";

    preorder(root->left);

    preorder(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);

    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);

    root->right->right = new TreeNode(5);

    string s;

    serialize(root, s);

    cout << "Serialized:\n";
    cout << s << endl;

    TreeNode* newRoot = deserialize(s);

    cout << "\nPreorder after deserialization:\n";
    preorder(newRoot);
}

