#include <iostream>
#include <deque>
using namespace std;

void print(deque<int> &dq)
{
    for(auto i: dq)
        cout<<i<<" ";
    cout << endl;
}

int main(){
    deque<int> dq;
    dq.push_front(5);
    dq.push_front(9);
    dq.push_front(-1);
    dq.pop_front();
    dq.push_back(12);
    dq.push_back(4);
    dq.pop_back();
    
    cout << dq.back();
}
