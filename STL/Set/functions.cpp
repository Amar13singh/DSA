#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s = {12,43,234,65,34,54,3,2,87,213,76,454};
    set < int > ::iterator it; // Creating iterator.
    it = s.begin();
    cout << "using begin() = " << * it << "\n";
    it = s.end();
    it--;
    cout << "using end() = " << * it << "\n";

    set < int > ::reverse_iterator rit; // Creating reverse iterator.
    rit = s.rbegin();
    cout << "using rbegin() = " << * rit << "\n";
    rit = s.rend();
    rit--;
    cout << "using rend() = " << * rit << "\n";

    return 0;
}
