#include<bits/stdc++.h>
#include <cstddef>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

public:
    Node()// default constructor..........
    {
        data = 0;
        next = NULL;
    }

    Node(int data)//parameterised constructor......
    {
        this->data = data;
        this->next = NULL;

    }

    Node(int data,Node* next)
    {
        this->data = data;
        this->next = next;
    }

};

Node* head;

void insertAtEnd(int data){

    Node* newNode = new Node(data);
    // temp = head;
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = newNode;

}

void insertAtK(int data,int key){//insert-At-Position k.....
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
    }

    Node* temp = head;
    int count = 1;
    while(temp->next!=NULL){
        if(count+1==key){
            Node* temp1=temp->next;
            temp->next=newNode;
            temp->next->next = temp1;

        }
        temp = temp->next; 
        count++;
    }

}

//alternate code

Node* insertPosition(int data,int key){
    Node* newNode = new Node(data);
    if(head == NULL){
        if(key==1){
            head = newNode;
            return head;
        }
        else{
            cout<<"Invalid Position";
            // return head;
        }
    }
    return head;
}

void printList(){
    Node* temp = head;
    if(temp==NULL){
        cout<<"Linked list is Empty";
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;

    }
    cout<<"NULL"<<endl;
}
 void reversePrintList(Node* head){
    Node* temp = head;
    if(head){
        reversePrintList(temp->next);
        cout<<temp->data<<"->";
    }    
}

int main(){
    // int a,b,c,d;
    // cout<<"Enter the Element You want to insert:";
    // cin>>a>>b>>c>>d;
    insertAtEnd(1);
    // insertAtEnd(3);
    // insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtK(2, 2);
    insertAtK(3, 3);
    insertAtK(4, 4);
    insertAtK(0, 1);
    printList();
    reversePrintList(head);
    cout<<"NULL"<<endl;
    
}