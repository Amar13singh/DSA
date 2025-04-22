#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Node {
public:
  int data;
  Node *prev;
  Node *next;

  Node(int data1, Node *next1, Node *prev1) {
    data = data1;
    prev = prev1;
    next = next1;
  }

  Node(int data1) {
    data = data1;
    prev = nullptr;
    next = nullptr;
  }
};
Node* head = NULL;

void insertAtBeg(int data) {
  Node *newNode = new Node(data);
  if (head == NULL) {
    head = newNode;
    return;
  } else {
    Node *temp = head;
    head = newNode;
    newNode->next = temp;
    newNode->prev = NULL;
    temp->prev = newNode;
    
  }
}

void printList() {
  Node *temp = head;

  // Check for empty list.
  if (head == NULL) {
    cout << "List empty" << endl;
    return;
  }

  // Traverse the list.
  while (temp != NULL) {
    cout << temp->data << "<->";
    temp = temp->next;
  }
}

int main() {
  // int a,b;
  // cout<<"Enter the Keys:";
  // cin>>a>>b;
  insertAtBeg(9);
  insertAtBeg(10);
  insertAtBeg(11);
  insertAtBeg(12);
  insertAtBeg(13);
//   insertAtEnd(8);
//   insertAtEnd(7);
  printList();
}

