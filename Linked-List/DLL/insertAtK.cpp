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

void insertAtK(int data,int key){
    Node *newNode = new Node(data);
    Node* temp = head;
    int counts = 1;

     //case 1: Insert at the head;
    if(key == 1){
        if(head == NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            
        }
        return;
    }
    while(temp!=NULL){
        
        if(counts+1==key){
            Node* temp1 = temp->next;
            temp->next = newNode;
            temp->next->prev = temp;
            newNode->next = temp1;//newNode->next = temp1;
            // temp->next->next->prev = temp->next;//temp1->prev = temp->next;
            if(temp1!=NULL){
                temp1->prev = temp->next;//temp1->prev = newNode;
            }
            return;
        }
        temp = temp->next;
        counts++;
    }
    if(temp == NULL && counts+1!=key){
            // cout<<"Invalid Position"<<endl;
            temp->next = newNode;
            newNode->prev = temp;
            return;
        }
}
void printList(){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    insertAtK(1, 1);
    insertAtK(2, 2);
    insertAtK(3, 3);
    // insertAtK(4, 4);
    // insertAtK(5, 5);
    insertAtK(6, 6);
    printList();
}