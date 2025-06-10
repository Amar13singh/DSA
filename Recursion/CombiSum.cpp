#include <bits/stdc++.h>
using namespace std;





    void dfs(int start,
         int remaining,
         const vector<int>& cand,
         vector<int>& current,
         vector<vector<int>>& result)
{
    if (remaining == 0) {
        result.push_back(current);
        return;
    }
    if (remaining < 0) return;

    for (int i = start; i < cand.size(); ++i) {
        int x = cand[i];
        if (x > remaining) continue;    // prune
        current.push_back(x);           // pick
        dfs(i, remaining - x, cand, current, result);
        current.pop_back();             // backtrack
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
    vector<int> current;
    dfs(0, target, candidates, current, result);
    return result;
        
        
    }


    int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;

}