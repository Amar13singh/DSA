#include<iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void midNode(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Mid Node: ";
    cout << slow->val << endl;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for(int i = 2; i <= 5; i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    cout << "Linked List: ";
    temp = head;
    while(temp){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
    midNode(head);
    return 0;
}