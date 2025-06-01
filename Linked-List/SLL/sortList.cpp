#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode*temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        temp=head;
        for(int i=0;i<arr.size();i++){
            temp->val=arr[i];
            temp=temp->next;
        }
        return head;

        
    }
};

int main(){
    // Create a sample linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    // Sort the list    
    Solution solution;
    head = solution.sortList(head);
    // Print the sorted list
    ListNode* current = head;
    cout << "Sorted List: ";
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
    return 0;
}
// Time Complexity: O(nlogn)
// Space Complexity: O(n)