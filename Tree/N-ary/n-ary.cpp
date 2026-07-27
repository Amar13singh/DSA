#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node(int v) {
        val = v;
    }
};

class NaryTree {
public:
    Node* root = nullptr;

    // Search
    Node* search(Node* node, int target) {
        if (node == nullptr)
            return nullptr;

        if (node->val == target)
            return node;

        for (Node* child : node->children) {
            Node* ans = search(child, target);
            if (ans)
                return ans;
        }

        return nullptr;
    }

    // Insert child
    void insert(Node* parent, int value) {
        if (parent == nullptr)
            return;

        parent->children.push_back(new Node(value));
    }

    // Preorder
    void preorder(Node* node) {
        if (!node)
            return;

        cout << node->val << " ";

        for (Node* child : node->children)
            preorder(child);
    }

    // Postorder
    void postorder(Node* node) {
        if (!node)
            return;

        for (Node* child : node->children)
            postorder(child);

        cout << node->val << " ";
    }

    // Level Order
    void levelOrder(Node* node) {
        if (!node)
            return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                Node* cur = q.front();
                q.pop();

                cout << cur->val << " ";

                for (Node* child : cur->children)
                    q.push(child);
            }

            cout << endl;
        }
    }

    // Height
    int height(Node* node) {
        if (!node)
            return 0;

        int h = 0;

        for (Node* child : node->children)
            h = max(h, height(child));

        return h + 1;
    }

    // Count Nodes
    int countNodes(Node* node) {
        if (!node)
            return 0;

        int cnt = 1;

        for (Node* child : node->children)
            cnt += countNodes(child);

        return cnt;
    }

    // Count Leaves
    int countLeaves(Node* node) {
        if (!node)
            return 0;

        if (node->children.empty())
            return 1;

        int ans = 0;

        for (Node* child : node->children)
            ans += countLeaves(child);

        return ans;
    }
};

int main() {

    NaryTree tree;

    //-----------------------
    // Create Root
    //-----------------------

    tree.root = new Node(1);

    //-----------------------
    // Level 1
    //-----------------------

    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    tree.root->children.push_back(n2);
    tree.root->children.push_back(n3);
    tree.root->children.push_back(n4);

    //-----------------------
    // Level 2
    //-----------------------

    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    n2->children.push_back(n5);
    n2->children.push_back(n6);

    n3->children.push_back(n7);

    n4->children.push_back(n8);

    //-----------------------
    // Insert
    //-----------------------

    tree.insert(n4, 9);
    tree.insert(n4, 10);

    /*
                1
          /     |      \
         2      3       4
       /  \      |    / | \
      5    6     7   8  9 10
    */

    cout << "Preorder\n";
    tree.preorder(tree.root);

    cout << "\n\n";

    cout << "Postorder\n";
    tree.postorder(tree.root);

    cout << "\n\n";

    cout << "Level Order\n";
    tree.levelOrder(tree.root);

    cout << "\n";

    cout << "Height = ";
    cout << tree.height(tree.root);

    cout << "\n";

    cout << "Total Nodes = ";
    cout << tree.countNodes(tree.root);

    cout << "\n";

    cout << "Leaf Nodes = ";
    cout << tree.countLeaves(tree.root);

    cout << "\n\n";

    //-----------------------
    // Search
    //-----------------------

    int key = 9;

    Node* ans = tree.search(tree.root, key);

    if (ans)
        cout << key << " Found\n";
    else
        cout << key << " Not Found\n";

    return 0;
}


