#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert element in sorted stack
void insertSorted(stack<int> &st, int val) {
    if (st.empty() || st.top() <= val) {
        st.push(val);
        return;
    }

    int top = st.top();
    st.pop();

    insertSorted(st, val);
    st.push(top);
}

// Main sort function using recursion
void sortStack(stack<int> &st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();

    sortStack(st);
    insertSorted(st, top);
}

// Utility to print stack (from top to bottom)
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original stack (top to bottom): ";
    printStack(st);

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    printStack(st);

    return 0;
}
