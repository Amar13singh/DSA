#include <bits/stdc++.h>    
using namespace std;


vector<int> lexicalOrder(int n) {
    vector<int> res;
    int curr = 1;
    for (int i = 0; i < n; i++) {
        res.push_back(curr);
        if (curr * 10 <= n) {
            curr *= 10;           // go to next level (e.g., 1 → 10)
        } else {
            if (curr >= n) curr /= 10;
            curr++;
            while (curr % 10 == 0) curr /= 10; // backtrack to next sibling
        }
    }
    return res;
}
 int main() {
    int n = 13;
    vector<int> ans = lexicalOrder(n);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}   