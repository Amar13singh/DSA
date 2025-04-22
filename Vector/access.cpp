#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declare a vector 'a' of integers
    vector<int> a;

    // Push values from 10 to 100 into vector 'a'
    for (int i = 1; i <= 10; i++)
        a.push_back(i * 10);

    // Use reference operator [g] to access the third element of vector 'a'
    cout << "\nReference operator [g] : a[2] = " << a[2];

    // Use at() to access the element at index 4 of vector 'a'
    cout << "\nat : a.at(4) = " << a.at(4);

    // Use front() to access the first element of vector 'a'
    cout << "\nfront() : a.front() = " << a.front();

    // Use back() to access the last element of vector 'a'
    cout << "\nback() : a.back() = " << a.back();

    // Use data() to get a pointer to the first element of vector 'a'
    int* pos = a.data();
    cout << "\nThe first element is " << *pos;

    return 0;
}
