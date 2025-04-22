#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node* convertArrToDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;//update temp....
    }

    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = convertArrToDLL(arr);
    Node* temp = head;
    while (temp!= nullptr) {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout<<endl;
    return 0;

}

