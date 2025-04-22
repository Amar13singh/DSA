#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
       Node *next;
       Node *prev;

       Node(int data){
           this->data = data;
           next = NULL;
           prev =NULL;
       }

       Node(int data, Node *next, Node *prev){
           this->data = data;
           this->next = next;
           this->prev = prev;
       }
};

Node *head = NULL;

//code for insert at end in Doubly Linked List
void insertAtEnd(int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    printList();
    return 0;

}