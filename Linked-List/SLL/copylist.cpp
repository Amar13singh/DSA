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

        unordered_map<Node*, Node*> mp;

        Node* temp = head;
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

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

    head->random = head->next->next;                    // 1 -> 3
    head->next->random = head;                          // 2 -> 1
    head->next->next->random = head->next->next->next->next; // 3 -> 5
    head->next->next->next->random = head->next->next;  // 4 -> 3
    head->next->next->next->next->random = head->next;  // 5 -> 2

    Solution solution;
    Node* copiedHead = solution.copyRandomList(head);

    // Printing the copied list
    while (copiedHead) {
        cout << "Node Value: " << copiedHead->val;
        if (copiedHead->random) {
            cout << ", Random Node Value: " << copiedHead->random->val << endl;
        } else {
            cout << ", Random Node Value: NULL" << endl;
        }
        copiedHead = copiedHead->next;
    }

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)