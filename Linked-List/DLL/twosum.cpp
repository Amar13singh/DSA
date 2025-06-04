#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to check if a pair exists with given sum
bool findPairWithSum(Node* head, int target) {
    if (!head) return false;

    // Get tail of DLL
    Node* tail = head;
    while (tail->next)
        tail = tail->next;

    Node* start = head;

    while (start != tail && start->prev != tail) {
        int sum = start->data + tail->data;

        if (sum == target) {
            cout << "Pair found: " << start->data << " + " << tail->data << " = " << target << endl;
            return true;
        }
        else if (sum < target)
            start = start->next;
        else
            tail = tail->prev;
    }

    return false;
}

// Helper to insert at the end of DLL
void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Driver code
int main() {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 4);
    append(head, 5);
    append(head, 6);
    append(head, 8);
    append(head, 9);

    int target = 10;

    if (!findPairWithSum(head, target))
        cout << "No pair with given sum found." << endl;

    return 0;
}
