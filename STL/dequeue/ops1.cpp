// Demonstration of deque STL
#include <iostream>
#include <deque>
using namespace std;

// To print contents of deque
void print (deque < int >dq)
{
    for (auto i:dq)
        cout << i << " ";
    cout << endl;
}

int main ()
{
    // Declaring deque as dq
    deque < int >dq;
    
    //1 is pushed from front
    dq.push_front (1);
    cout << "The deque dq is : ";
    print (dq);
    
    //2 is pushed from back
    dq.push_back (2);
    cout << "The deque dq is : ";
    print (dq);
    
    //3 is pushed from front
    dq.push_front (3);
    cout << "The deque dq is : ";
    print (dq);
    
    //4 is pushed from back
    dq.push_back (4);
    cout << "The deque dq is : ";
    print (dq);
    
    //5 is pushed from front
    dq.push_back (5);
    cout << "The deque dq is : ";
    print (dq);
    
    //maximum size of deque
    cout << "dq.max_size() : " << dq.max_size () << endl;
    //current size of deque
    cout << "dq.size() : " << dq.size () << endl;
    
    //element at front
    cout << "dq.front() : " << dq.front () << endl;
    //element at back
    cout << "dq.back() : " << dq.back () << endl;
    
    //element at index 3
    cout << "dq.at(3) : " << dq.at (3) << endl;
    
    cout << "dq.pop_back() : ";
    dq.pop_back ();
    print (dq);
    
    cout << "dq.pop_front() : ";
    dq.pop_front ();
    print (dq);

  return 0;
}

