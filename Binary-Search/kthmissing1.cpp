#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] - (mid + 1) < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low + k;

}

int main(){
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int result = findKthPositive(arr, k);
    cout << "The " << k << "th missing positive integer is: " << result << endl;
}

// Time Complexity: O(log(n))
// Space Complexity: O(1)