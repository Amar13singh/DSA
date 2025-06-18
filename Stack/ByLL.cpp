#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    // Push operation
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop operation
    void pop() {
        if (topNode == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Top (peek) operation
    int top() {
        if (topNode == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    // Check if empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Display elements
    void display() {
        Node* temp = topNode;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();        // Output: 30 20 10
    cout << s.top() << endl;  // Output: 30
    s.pop();
    s.display();        // Output: 20 10
    cout << s.top() << endl;  // Output: 20
}
