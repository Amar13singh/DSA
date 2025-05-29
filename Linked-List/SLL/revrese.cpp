#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;     // Store next node
        current->next = prev;     // Reverse current node's pointer
        prev = current;           // Move prev to current
        current = next;           // Move current to next
    }

    return prev; // New head
}

// Utility function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Example usage
int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for (int i = 2; i <= 5; i++) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
