#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            ListNode* kth = prevGroupEnd;
            // Find the kth node
            for (int i = 0; i < k && kth; ++i) {
                kth = kth->next;
            }
            if (!kth) break;  // Less than k nodes left

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = kth;
            ListNode* nextGroupStart = kth->next;

            // Reverse the group
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;

            while (curr != nextGroupStart) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevGroupEnd->next = groupEnd;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};

// Utility function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Example usage
int main() {
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for (int i = 2; i <= 7; ++i) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    cout << "Original List: ";
    printList(head);

    Solution sol;
    int k = 3;
    ListNode* newHead = sol.reverseKGroup(head, k);

    cout << "Reversed in K Group List (k=" << k << "): ";
    printList(newHead);

    return 0;
}
