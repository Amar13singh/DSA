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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1: Split the list into two halves
        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;  // Cut the list

        // Step 2: Sort each half recursively
        left = sortList(left);
        right = sortList(right);

        // Step 3: Merge sorted halves
        return merge(left, right);
    }

private:
    // Function to find the middle node
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Append remaining nodes
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};


int main(){
    // Create a sample linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    // Sort the list    
    Solution solution;
    head = solution.sortList(head);
    // Print the sorted list
    ListNode* current = head;
    cout << "Sorted List: ";
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
    return 0;
}
// Time Complexity: O(n log n)
// Space Complexity: O(log n)