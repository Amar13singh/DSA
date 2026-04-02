#include <bits/stdc++.h>
using namespace std;

int main() {
    
  priority_queue < int > pq;
  
  pq.push(5);
  pq.push(3);
  pq.push(4);
  pq.push(1);
  pq.push(2);
  
  cout << "Top element: " << pq.top() << endl;
  
  cout << "Size of the queue: " << pq.size() << endl;
  
  cout << "Is the queue empty? " << pq.empty() << endl;
  
  pq.pop();
  
  cout << "Top element: " << pq.top() << endl;
  
  cout << "Size of the queue: " << pq.size() << endl;
  
  cout << "Is the queue empty? " << pq.empty() << endl;
  
  priority_queue < int > pq2;
  
  pq2.push(5);
  pq2.push(3);
  pq2.push(4);
  pq2.push(1);
  pq2.push(2);
 
  pq2.swap(pq);
 
  cout << "Top element: " << pq.top() << endl;
 
  cout << "Size of the queue: " << pq.size() << endl;
 
  cout << "Is the queue empty? " << pq.empty() << endl;
 
  cout << "Top element: " << pq2.top() << endl;
 
  cout << "Size of the queue: " << pq2.size() << endl;
 
  cout << "Is the queue empty? " << pq2.empty() << endl;
 
  priority_queue < int > pq3;
 
  pq3.push(5);
  pq3.push(3);
  pq3.push(4);
  pq3.push(1);
  pq3.push(2);
 
  pq3.emplace(6);
 
  cout << "Top element: " << pq3.top() << endl;
 
  cout << "Size of the queue: " << pq3.size() << endl;
 
  cout << "Is the queue empty? " << pq3.empty() << endl;

  return 0;
}
