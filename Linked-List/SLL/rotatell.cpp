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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Get length and tail
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Step 2: Connect tail to head (make it circular)
        tail->next = head;

        // Step 3: Find new tail: (len - k % len - 1) steps from head
        int stepsToNewTail = len - k % len;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        // Step 4: Set new head and break the ring
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};


int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int k = 2;
    ListNode* result = solution.rotateRight(head, k);
    // Print the rotated list
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}