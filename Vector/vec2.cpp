#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declare a vector 'a' of integers
    vector<int> a;

    // Initialize vector 'a' with values from 1 to 5
    for (int i = 1; i <= 5; i++)
        a.push_back(i);

    // Print the size of the vector 'a'
    cout << "Size : " << a.size();

    // Print the capacity of the vector 'a'
    cout << "\nCapacity : " << a.capacity();

    // Print the maximum size of the vector 'a'
    cout << "\nMax_Size : " << a.max_size();

    // Resize vector 'a' to size 4
    a.resize(4);
    cout << "\nSize : " << a.size();

    // Check if vector 'a' is empty
    if (!a.empty())
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    return 0;
}
