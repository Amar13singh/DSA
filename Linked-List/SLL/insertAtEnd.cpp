#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
class Node{
public:    
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = NULL;
    }

    // Node()

    Node(int data1,Node* head){
        data = data1;
        next = head;
        
    }
};

Node* head = NULL;

void insertAtEnd(int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head =newNode;
    }
    else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = newNode;
        
    }
}


void printList()
{
	Node* temp = head;

	// Check for empty list.
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
}



int main(){
    // int a,b;
    // cout<<"Enter the Keys:";
    // cin>>a>>b;
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);    
    insertAtEnd(5);
    insertAtEnd(6);




    printList();
}