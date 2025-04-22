#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declare vectors 'a', 'a1', and 'a2' of integers
    vector<int> a;
    vector<int> a1, a2;

    // Assign 4 elements with value 7 to vector 'a'
    a.assign(4, 7);

    // Print the contents of vector 'a'
    cout << "The vector contains: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    // Add an element with value 10 to the end of vector 'a'
    a.push_back(10);
    int n = a.size();
    cout << "The last element is: " << a[n - 1] << endl;

    // Remove the last element from vector 'a'
    a.pop_back();
    cout << "The vector contains: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    // Insert element with value 3 at the beginning of vector 'a'
    a.insert(a.begin(), 3);
    cout << "The first element is: " << a[0] << endl;

    // Erase the first element from vector 'a'
    a.erase(a.begin());
    cout << "The first element is: " << a[0] << endl;

    // Clear all elements from vector 'a'
    a.clear();
    cout << "Vector size after erase(): " << a.size() << endl;

    // Push values to vectors 'a1' and 'a2'
    a1.push_back(3);
    a1.push_back(4);
    a2.push_back(5);
    a2.push_back(6);

    // Print vectors 'a1' and 'a2'
    cout << "\nVector 1 is: ";
    for (int i = 0; i < a1.size(); i++)
        cout << a1[i] << " ";
    cout << "\nVector 2 is: ";
    for (int i = 0; i < a2.size(); i++)
        cout << a2[i] << " ";

    // Swap vectors 'a1' and 'a2'
    a1.swap(a2);
    cout << "\nAfter Swap \nVector 1 is: ";
    for (int i = 0; i < a1.size(); i++)
        cout << a1[i] << " ";
    cout << "\nVector 2 is: ";
    for (int i = 0; i < a2.size(); i++)
        cout << a2[i] << " ";

    return 0;
}
