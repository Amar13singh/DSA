#include<bits/stdc++.h>
using namespace std;



struct Node{
    int val;
    Node* next;

    Node(int x){
        val=x;
        next=nullptr;
    }
};

struct cmp {
        bool operator()(Node* a, Node* b) {
            return a->val > b->val;
        }
    };

Node* mergeKLists(vector<Node*>&lists){

    priority_queue<Node*,vector<Node*>,cmp>pq;

    for(auto node:lists){
        if(node){
            pq.push(node);
        }
    }

    Node ans(0);
    Node* temp= &ans;

    while(!pq.empty()){
        Node* curr=pq.top();
        pq.pop();
        temp->next=curr;
        temp = curr;

        if(curr->next) pq.push(curr->next);
    }
    return ans.next;

}



// Print Linked List
void printList(Node* head) {
    while (head) {
        cout << head->val;

        if (head->next)       //good to use 
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}



int main() {

    // List 1 : 1 -> 4 -> 7
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(7);

    // List 2 : 2 -> 5 -> 8
    Node* l2 = new Node(2);
    l2->next = new Node(5);
    l2->next->next = new Node(8);

    // List 3 : 3 -> 6 -> 9
    Node* l3 = new Node(3);
    l3->next = new Node(6);
    l3->next->next = new Node(9);

    vector<Node*> lists = {l1, l2, l3};

    cout << "Input Lists:\n";
    printList(l1);
    printList(l2);
    printList(l3);

    Node* ans = mergeKLists(lists);

    cout << "\nMerged List:\n";
    printList(ans);

    return 0;
}

// Time	Complexity: O(N log k)
// Auxiliary Space:	O(k)