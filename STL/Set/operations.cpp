#include<bits/stdc++.h>
using namespace std;

int main() {
    
  set<int> s ={12,43,234,65,34,54,3,2,87,213,76,454};

  set<int>::iterator it;

  it = s.find(54);
  cout << "The iterator is pointing to - " << * it << "\n";

  if (s.count(234)) {
    cout << "The value is present in the set" << "\n";
  } else {
    cout << "The value is not present in the set" << "\n";
  }

  it = s.lower_bound(10);
  cout << "The lower_bound of 10 is " << * it << "\n";

  it = s.upper_bound(12);
  cout << "The upper_bound of 12 is " << * it << "\n";

  return 0;
}
