#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        // Make sure headA is the longer list
        if (lenA < lenB) {
            swap(headA, headB);
            swap(lenA, lenB);
        }

        // Advance the longer list by the length difference
        int diff = lenA - lenB;
        while (diff--) {
            headA = headA->next;
        }

        // Traverse both lists together to find the intersection
        while (headA && headB) {
            if (headA == headB) return headA; // Intersection found
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr; // No intersection
    }
};

int main() {
    // Create intersection node
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // Create first list: 3 -> 7 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    // Create second list: 99 -> 1 -> 8 -> 10
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

    Solution solution;
    ListNode* intersection = solution.getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection.\n";
    }

    return 0;
}
