#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }

        ListNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Function to delete the first node with given key
    void deleteByKey(int key) {
        if (!head) return;

        // If head needs to be deleted
        if (head->val == key) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr) {
            if (curr->val == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Print the list
    void print() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    cout << "Original List: ";
    list.print();
    list.deleteByKey(3);
    cout << "List after deleting 3: ";
    list.print();
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)