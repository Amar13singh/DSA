#include<bits/stdc++.h>
using namespace std;


    void minHeapify(vector<int>& arr, int n, int i)
    {
        int smallest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(arr, n, smallest);
        }
    }

    void convertMaxToMin(vector<int>& arr)
    {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--)
            minHeapify(arr, n, i);
    }


int main(){
    vector<int> arr1={100,90,80,70,60,50,40,20,10};
    // vector<int> arr2={20,10,20,40,50,30,90,80,100,60,70};
    convertMaxToMin(arr1);
    cout<<"min heap is: ";
    for(int x:arr1) cout<<x<<" ";

}