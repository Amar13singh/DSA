#include <iostream>
using namespace std;

class ListNode {
    public:
    int val; 
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};  


ListNode* middleNode(ListNode* head) {
    ListNode* temp = head;
    int count = 0;
    while(temp){
        temp = temp->next;
        count++;
    }
    count = count/2;
    ListNode* temp1 = head;
    for(int i = 1;i<=count;i++){
        temp1 = temp1->next;
    }
    return temp1;
    
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for(int i=2;i<=6;i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    ListNode* ans = middleNode(head);
    cout<<"Middle Node is: ";
    cout<<ans->val<<endl;
    return 0;

}
   