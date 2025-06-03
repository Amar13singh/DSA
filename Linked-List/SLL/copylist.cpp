#include <iostream>
#include <unordered_map>
using namespace std;




class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create copies and map original -> copy
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Step 2: Assign next and random using the map
        temp = head;
        while (temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};

int main() {
    // Creating a sample linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;
    Solution solution;
    Node* copiedHead = solution.copyRandomList(head);
    // Printing the copied list (optional)
    while (copiedHead) {
        cout << "Node Value: " << copiedHead->val;
        if (copiedHead->random) {
            cout << ", Random Node Value: " << copiedHead->random->val << endl;
        } else{
        cout << ", Random Node Value: NULL" << endl;
        copiedHead = copiedHead->next;
        }
        return 0;
    }
    // return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)