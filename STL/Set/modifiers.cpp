#include<bits/stdc++.h>
using namespace std;

int main() {
    
  set<int> s = {12,43,234,65,34,54,3,2,87,213,76,454};

  s.insert(9);
  cout << "set after inserting 9 is - " << "\n";
  for (auto i: s) {
    cout << i << " ";
  }
  cout << "\n";

  s.erase(234);
  cout << "set after removing 234 is - " << "\n";
  for (auto i: s) {
    cout << i << " ";
  }
  cout << "\n";

  s.emplace(69);
  cout << "set after emplacing 69 is - " << "\n";
  for (auto i: s) {
    cout << i << " ";
  }
  cout << "\n";

  set<int>s2 = {23,43,54,12,67,87,9,54,32,87,3,1}; // Creating a new set.
  swap(s, s2); // Swapping the contents of both sets.
  cout << "the set s after swapping" << "\n";
  for (auto i: s) {
    cout << i << " ";
  }
  cout << "\n";
  cout << "the set s2 after swaping" << "\n";
  for (auto i: s2) {
    cout << i << " ";
  }
  cout << "\n";

  cout << "Size of the set before using set.clear() = " << s.size() << "\n";
  s.clear();
  cout << "Size of the set after using set.clear() = " << s.size() << "\n";
  return 0;
}
