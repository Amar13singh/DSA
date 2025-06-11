#include <iostream>
#include <vector>
using namespace std;

void backtrack(int start, int k, int target, vector<int>& path, vector<vector<int>>& result) {
    if (path.size() == k && target == 0) {
        result.push_back(path);
        return;
    }
    if (path.size() >= k || target <= 0) return;

    for (int i = start; i <= 9; i++) {
        path.push_back(i);
        backtrack(i + 1, k, target - i, path, result);
        path.pop_back(); // backtrack
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(1, k, n, path, result);
    return result;
}

int main() {
    int k = 3, n = 7;
    auto res = combinationSum3(k, n);
    for (auto& combo : res) {
        cout << "[ ";
        for (int num : combo) cout << num << " ";
        cout << "]\n";
    }
    return 0;
}
