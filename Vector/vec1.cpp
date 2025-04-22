#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declare a vector 'a' of integers
    vector<int> a;

    // Initialize vector 'a' with values from 1 to 7
    for (int i = 1; i <= 7; i++)
        a.push_back(i);

    // Print the output of vector 'a' using iterators begin() and end()
    cout << "Output of begin and end Function: ";
    for (auto i = a.begin(); i != a.end(); ++i)
        cout << *i << " ";
    cout << endl;
    // cout << i <<endl;

    // Print the output of vector 'a' using iterators cbegin() and cend()
    cout << "Output of cbegin and cend Function: ";
    for (auto i = a.cbegin(); i != a.cend(); ++i)
        cout << *i << " ";
    cout << endl;

    // Print the output of vector 'a' using iterators rbegin() and rend()
    cout << "Output of rbegin and rend Function: ";
    for (auto ir = a.rbegin(); ir != a.rend(); ++ir)
        cout << *ir << " ";
    cout << endl;

    // Print the output of vector 'a' using iterators crbegin() and crend()
    cout << "Output of crbegin and crend Function: ";
    for (auto ir = a.crbegin(); ir != a.crend(); ++ir)
        cout << *ir << " ";
    cout << endl;

    return 0;
}

