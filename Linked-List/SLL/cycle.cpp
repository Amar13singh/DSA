#include <iostream>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


void insertAtEnd(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return true;
        }

    }
        return false; //no cycle
}


int main() {
    ListNode* head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    // Create a cycle for testing
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head->next;
    if(hasCycle(head)){
        cout<<"cycle detected!"<<endl;
    }else{
        cout<<"No Cycle."<<endl;
    }

    return 0;
}

// Time Complexity:O(n)
// Space Complexity:O(1)