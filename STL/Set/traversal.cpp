#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s = {12,43,234,65,34,54,3};
    
    set<int>::iterator it;  // Creating the iterator.
    	
    for (it = s.begin(); it != s.end(); it++)
    {
    	cout << *it << " ";
    }
    
    return 0;
}
