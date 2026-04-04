#include "iostream"
#include "stack"
using namespace std;

// Function to return precedence of operators
int prec(const char &ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix  expression
void infixToPostfix(const string &s)
{

    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <=  'Z') || (c >= '0' && c <= '9'))
            result.push_back(c);

        // If the scanned character is an '(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’, pop and output string from the stack until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result.push_back(st.top());
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned.
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top ()))
            {
                result.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    cout << "Result: " << result << endl;
}

// Driver program to test the above functions
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}

