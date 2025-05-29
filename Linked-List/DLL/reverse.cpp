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

    // Reverse the doubly linked list
    void reverse() {
        ListNode* current = head;
        ListNode* prevNode = nullptr;

        while (current) {
            // Swap next and prev pointers
            ListNode* nextNode = current->next;
            current->next = prevNode;
            current->prev = nextNode;

            // Move pointers forward
            prevNode = current;
            current = nextNode;
        }

        head = prevNode;
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
    dll.reverse();
    cout << "Reversed List: ";
    dll.print();
    return 0;

}

