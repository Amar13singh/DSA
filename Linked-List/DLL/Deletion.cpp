#include <iostream>
using namespace std;

// Node class
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    ListNode* head;

    DoublyLinkedList() : head(nullptr) {}

    // Insert at end
    void insert(int value) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete node with a given key
    void deleteByKey(int key) {
        if (!head) return;

        ListNode* temp = head;

        // If head needs to be deleted
        if (head->val == key) {
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }

        // Search for the node
        while (temp && temp->val != key) {
            temp = temp->next;
        }

        if (!temp) return; // Key not found

        // Remove the node
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;

        delete temp;
    }

    // Print the list
    void print() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    DoublyLinkedList dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);
    dll.insert(5);
    cout << "Original List: ";
    dll.print();
    dll.deleteByKey(3);
    cout << "List after deleting 3: ";
    dll.print();
    return 0;
}