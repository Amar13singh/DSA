// Problem Statement: Given an array arr[] and a number k . The array 
// is sorted in a way that every element is at max k distance away from
//  it sorted position. It means if we completely sort the array, then the 
// index of the element can go from i - k to i + k where i is index in the
//  given array. Our task is to completely sort the array.
#include<bits/stdc++.h>
using namespace std;

vector<int>nearlySorted(vector<int>&arr,int k){
    int n= arr.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>ans;

    for(int i=0;i<n;i++){
        pq.push(arr[i]);

        if(pq.size()>k+1){
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}



void print(vector<int>& v) {
    for (int x : v)
        cout << x << " ";
    cout << "\n";
}

int main() {

    // Example 1
    vector<int> arr1 = {6, 5, 3, 2, 8, 10, 9};
    int k1 = 3;

    cout << "Example 1\n";
    cout << "Input : ";
    print(arr1);

    auto ans1 = nearlySorted(arr1, k1);

    cout << "Output: ";
    print(ans1);


    // Example 2
    vector<int> arr2 = {10, 9, 8, 7, 4, 70, 60, 50};
    int k2 = 4;

    cout << "\nExample 2\n";
    cout << "Input : ";
    print(arr2);

    auto ans2 = nearlySorted(arr2, k2);

    cout << "Output: ";
    print(ans2);


    // Example 3 (duplicates + negatives)
    vector<int> arr3 = {-3, -5, -4, 0, 2, 1, 3, 3, 5, 4};
    int k3 = 2;

    cout << "\nExample 3\n";
    cout << "Input : ";
    print(arr3);

    auto ans3 = nearlySorted(arr3, k3);

    cout << "Output: ";
    print(ans3);

    return 0;
}