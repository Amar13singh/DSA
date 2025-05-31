#include<bits/stdc++.h>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int countLoppLength(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            int count = 1;
            ListNode* temp = slow;
            while(temp->next != slow){
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    return 0;


}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for(int i = 2; i <= 5; i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    temp->next = head->next;
    cout << countLoppLength(head) << endl;
    return 0;

}