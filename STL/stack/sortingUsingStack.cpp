#include "iostream"
#include "stack"
#include "vector"

using namespace std;

stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;
    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();

        while (!tmpStack.empty() && tmpStack.top() < tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }

    return tmpStack;
}

void sortUsingStack(vector<int> &arr)
{
    const int n = arr.size();
    stack<int> input;
    for (int i = 0; i < n; i++)
        input.push(arr[i]);

    stack<int> tmpStack = sortStack(input);

    for (int i = 0; i < n; i++)
    {
        arr[i] = tmpStack.top();
        tmpStack.pop();
    }
}

int main()
{
    vector<int> v = {2, 30, -5, 43, 100};

    sortUsingStack(v);

    for (const int &i : v)
        cout << i << ' ';

    return 0;
}
