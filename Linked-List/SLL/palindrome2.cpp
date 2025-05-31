#include<iostream>
using namespace std;


class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // 1. Count the number of nodes
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        
        // 2. Move to the middle
        int mid = count/2;
        ListNode* firstHalf = head;
        ListNode* secondHalf = head;
        for (int i = 0; i < mid; ++i) {
            secondHalf = secondHalf->next;
        }
        // If odd, skip the middle node
        if (count % 2 != 0) {
            secondHalf = secondHalf->next;
        }
        
        // 3. Reverse the second half
        ListNode* prev = nullptr;
        while (secondHalf) {
            ListNode* nextTemp = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = nextTemp;
        }
        
        // 4. Compare values in both halves
        ListNode* p1 = head;
        ListNode* p2 = prev;
        for (int i = 0; i < mid; ++i) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
int main(){
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    int arr[] = {2, 3, 2, 1};
    for(int i = 0; i < 4; i++){
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    cout << "Linked List: ";
    temp = head;
    while (temp) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "Is Palindrome: " << (isPalindrome(head) ? "true" : "false") << endl;
    return 0;
    
}
// Time Complexity: O(N)
// Space Complexity: O(1)