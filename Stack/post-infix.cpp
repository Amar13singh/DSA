#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char c) {
    string ops = "+-*/%^~#";
    return ops.find(c) != string::npos;
}

bool isUnary(char c) {
    return c == '~' || c == '#';  // ~ for bitwise NOT, # for negation
}

string postfixToInfix(string postfix) {
    stack<string> s;
    for (char c : postfix) {
        if (c == ' ') continue;

        if (isalnum(c)) {
            s.push(string(1, c));
        } else if (isOperator(c)) {
            if (isUnary(c)) {
                string op1 = s.top(); s.pop();
                string expr = "(" + string(1, c) + op1 + ")";
                s.push(expr);
            } else {
                string op2 = s.top(); s.pop();
                string op1 = s.top(); s.pop();
                string expr = "(" + op1 + string(1, c) + op2 + ")";
                s.push(expr);
            }
        }
    }
    return s.top();
}

int main() {
    string postfix = "AB+CD%^";  // Equivalent to ((A + B) ^ (C % D))
    cout << "Infix: " << postfixToInfix(postfix) << endl;
    return 0;
}
