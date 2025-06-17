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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        // If front becomes NULL, update rear too
        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    // Get front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Print all elements
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"Queue: ";
    q.display();        // Output: 10 20 30
    cout<<"Front: ";
    cout << q.peek() << endl; // Output: 10
    cout<<"After Dequeue: ";
    q.dequeue();
    q.display();        // Output: 20 30
    cout<<"Front: ";
    cout << q.peek() << endl; // Output: 20
}
