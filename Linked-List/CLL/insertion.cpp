#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
      int data;
      Node *next;

      Node(int data){
          this->data = data;
          next = NULL;
      }
      Node(int data, Node *next){
          this->data = data;
          this->next = next;
      }
};
Node *head = NULL;
void insertAtEnd(int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        head->next = head;
        return;
    }
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
 void insertAtBeg(int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        head->next = head;
        return;
    }
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}
 void insertAtK(int data, int k){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        head->next = head;
        return;
    }
    if(k == 1){
        Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *temp = head;
    int count = 1;
    while(temp->next != head && count < k-1){
        temp = temp->next;
        count++;
    }
    if(temp->next == head && count != k-1){
        cout<<"Invalid Position"<<endl;
        return;
    }
    Node *temp1 = temp->next;
    temp->next = newNode;
    newNode->next = temp1;
}
void printList(){
    Node *temp = head;
    while(temp->next != head){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
int main(){
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtBeg(0);
    insertAtK(6, 7);
    printList();
    return 0;
}

