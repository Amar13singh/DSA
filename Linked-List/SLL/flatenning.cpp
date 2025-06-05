#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    // Helper to merge two sorted lists
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        if (a->data < b->data) {
            a->child = merge(a->child, b);
            return a;
        } else {
            b->child = merge(a, b->child);
            return b;
        }
    }

    // Main flatten function
    Node* flatten(Node* head) {
        if (!head || !head->next) return head;

        // Recursively flatten the right side
        head->next = flatten(head->next);

        // Merge current list with flattened right side
        head = merge(head, head->next);

        // Set next to null in the final flattened list
        head->next = nullptr;

        return head;
    }
};
// Helper function to print the flattened list
void printFlattenedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}


int main() {
    // Create the nodes
    Node* head = new Node(5);
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next = new Node(10);
    head->next->child = new Node(20);

    head->next->next = new Node(19);
    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    // Call flatten
    Solution sol;
    Node* flattened = sol.flatten(head);

    // Print result
    cout << "Flattened list: ";
    printFlattenedList(flattened);

    return 0;
}    
