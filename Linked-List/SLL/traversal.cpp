//linkedlist
//Implementation of a Linked List in C++
//traversal
#include<bits/stdc++.h>
// #include <cstddef>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    public:
        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }
    public:
        Node(int data1){
            data =data1;
            next = nullptr;
        }
    

};

Node* ConvertArr2LL(vector<int> &arr)
{
        Node* head = new Node(arr[0]);
        Node *mover = head;
        for(int i=1;i<arr.size();i++){
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;//mover->next->next = temp;

        }
        return head;

}

int lengthOfLL(Node* head)
{
    int count = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}


bool checkifPresent(Node* head,int value)
{
    Node* temp = head;
    while(temp)
    {
        if(temp->data == value){
            return true;
        }
        // else {
        // return false;
        // }

        temp= temp->next;
    }

    return false;
}



void printList(Node* head) 
{ 
	Node* temp = head;

	// Check for empty list.
	if (head == NULL) { 
		cout << "List empty" << endl; 
		return; 
	} 

	// Traverse the list.
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int main()
{
    vector<int>arr ={2,5,8,7};
    Node* head = ConvertArr2LL(arr);
    Node* temp = head;
    while(temp)
    {
        cout<<temp->data<<"\n ";
        temp = temp->next;
        cout<<temp<<"\n"<<head<<"\n";
    }

    cout<<"Length of the LinkedList is:"<<lengthOfLL(head)<<"\n";
    cout<<checkifPresent(head, 4)<<"\n";// 0
    cout<<checkifPresent(head, 8);// 1
    
    return 0;

    

}
