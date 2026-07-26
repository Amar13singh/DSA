#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};


void levelOrder(Node* root){
    queue<Node*>q;

    if(root==nullptr) return;

    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        cout<<node->val<<" ";

        if(node->left)
            q.push(node->left);

        if(node->right)
            q.push(node->right);

    }

}

int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"LevelOrder is:";
    levelOrder(root);
}