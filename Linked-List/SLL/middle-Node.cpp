//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
Node *head = NULL;
void insertAtEnd(int x){
    Node *newNode = new Node(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    // return head;
}
void middleNode(Node *head){
    Node *temp = head;
    int count = 1;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    // count = count/2;
    Node *temp1 = head;
    int count1 = count;
    count = count/2;
    for(int i=1;i<count;i++){
        temp1 = temp1->next;
    }
    if(count1%2 == 0){
        cout<<"1st Middle Node is: "<<temp1->data<<endl;
        cout<<"2nd Middle Node is: "<<temp1->next->data<<endl;
    }
    else{
        cout<<"Middle Node is: "<<temp1->next->data<<endl;
    }
};

int main(){
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtEnd(7);
    // insertAtEnd(8);
    // insertAtEnd(9);
    // insertAtEnd(10);
    middleNode(head);
    return 0;
}


  