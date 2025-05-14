#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int k = 3;
    int low = 0, high = n - 1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==k){
            cout<<"Element found at index: "<<mid<<endl;
            return 0;
        }
        else if(arr[mid]<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
}
// Time Complexity: O(log n)
// Space Complexity: O(1)