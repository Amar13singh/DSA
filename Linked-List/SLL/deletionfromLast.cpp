#include<iostream>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move fast to the end, maintaining the gap
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        return dummy->next;
    }


int main() {
        // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        int n = 2;
        // Remove the nth node from the end
        ListNode* result = removeNthFromEnd(head, n);
        // Print the result
        cout << "Result: ";
        while (result != nullptr) {
            cout << result->val << " ";
            result = result->next;
        }
        return 0;
    }