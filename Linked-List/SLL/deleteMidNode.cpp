#include<iostream>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;  // Base case: 0 or 1 node
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 'slow' is now at the middle node, 'prev' is node before it
        prev->next = slow->next;  // Delete the middle node
        delete slow;

        return head;
    }
};


int main(){
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // Delete the middle node
    Solution solution;
    head = solution.deleteMiddle(head);
    // Print the result
    ListNode* current = head;
    cout << "Linked List after deleting middle node: ";
    while (current)
    {
        cout << current->val << "->";
        current = current->next;
    }
    cout <<"NULL"<< endl;
    return 0;
}