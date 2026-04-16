#include <bits/stdc++.h>
using namespace std;

int getPid(vector<int>& arr) {
    unordered_map<int, int> freq;
    int bestPid = INT_MAX;
    int bestFreq = 0;

    for (int pid : arr) {
        freq[pid]++;

        if (freq[pid] > bestFreq ||
           (freq[pid] == bestFreq && pid < bestPid)) {
            bestFreq = freq[pid];
            bestPid = pid;
        }
    }

    return bestPid;
}

int main(){
    vector<int> arr= {4, 1, 2, 1, 2, 2, 4, 4};
    cout<<"Lowest id is:"<<getPid(arr);
    
}