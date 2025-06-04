#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Deletes all occurrences of a key in DLL
Node* deleteAllOccurrences(Node* head, int key) {
    Node* curr = head;

    while (curr) {
        if (curr->data == key) {
            Node* toDelete = curr;

            // If node is head
            if (curr == head) {
                head = curr->next;
                if (head) head->prev = nullptr;
            }
            else {
                if (curr->prev) curr->prev->next = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
            }

            curr = curr->next;
            delete toDelete;
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}

// Helper function to print DLL
void printDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    // DLL: 10 <-> 20 <-> 10 <-> 30 <-> 10 <-> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(10);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(30);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original DLL: ";
    printDLL(head);

    int key = 10;
    head = deleteAllOccurrences(head, key);

    cout << "DLL after deleting all occurrences of " << key << ": ";
    printDLL(head);

    return 0;
}
