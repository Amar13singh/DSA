#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    string ops = "+-*/%^~#";
    return ops.find(c) != string::npos;
}

bool isUnary(char c) {
    return c == '~' || c == '#';
}

string prefixToInfix(string prefix) {
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c == ' ') continue;

        if (isalnum(c)) {
            s.push(string(1, c));
        } else if (isOperator(c)) {
            if (isUnary(c)) {
                string op1 = s.top(); s.pop();
                string expr = "(" + string(1, c) + op1 + ")";
                s.push(expr);
            } else {
                string op1 = s.top(); s.pop();
                string op2 = s.top(); s.pop();
                string expr = "(" + op1 + string(1, c) + op2 + ")";
                s.push(expr);
            }
        }
    }
    return s.top();
}

int main() {
    string prefix = "^+AB%C D"; // adjust to avoid whitespace if needed
    cout << "Infix: " << prefixToInfix(prefix) << endl;
    return 0;
}
