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

int width(TreeNode* root){
    if(!root) return 0;

    long long ans = 0;

    queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();

            long long first = q.front().second;
            long long last = first;

            for (int i = 0; i < size; i++) {

                auto [node, index] = q.front();
                q.pop();

                index -= first;   // Normalize

                last = index;

                if (node->left)
                    q.push({node->left, 2 * index + 1});

                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }

            ans = max(ans, last + 1);
        }

        return ans;
}

int main(){
    TreeNode* root = new Node(1);
    
}