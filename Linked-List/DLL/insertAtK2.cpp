#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
      int data;
      Node *next;
      Node *prev;

      Node(int data){
          this->data = data;
          next = NULL;
          prev = NULL;
      }
      Node(int data, Node *next, Node *prev){
          this->data = data;
          this->next = next;
          this->prev = prev;
      }
};
Node *head = NULL;
void insertAtK(int data, int k){
    Node *newNode = new Node(data);
     //Edge Case 1: Invalid position
     if(k < 1){
        cout<<"Invalid Position"<<endl;
        return;
    }
    //Insert at the head

    if(head == NULL){
        head = newNode;//list is empty
        return;
    }

    if(k == 1){
        Node *temp = head;
        head = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        return;
    }
    //transverse to the k-1th node
    Node *temp = head;
    int count = 1;
    while(temp->next != NULL && count < k-1){
        temp = temp->next;
        count++;
    }
    //position exceeds the length of the list
    if(temp == NULL && count != k-1){
        cout<<"Invalid Position"<<endl;
        return;
    }
    //insert at the end
    if(temp->next == NULL){
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }
    //insert at the middle
    Node *temp1 = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = temp1;
    temp1->prev = newNode;
    
};
void printList(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void reversePrintList(){
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}

int main(){
    insertAtK(1,1);
    insertAtK(2,2);
    insertAtK(3,3);
    insertAtK(4,4);
    insertAtK(5,5);
    insertAtK(6,6);
    // insertAtK(7,1);
    printList();
    reversePrintList();
    return 0;
}