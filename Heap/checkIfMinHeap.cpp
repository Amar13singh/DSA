#include<bits/stdc++.h>
using namespace std;

bool isMinHeap(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n / 2; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left])
            return false;

        if (right < n && arr[i] > arr[right])
            return false;
    }

    return true;
}

int main(){
    vector<int> arr1={10,20,40,50,30,90,80,100,60,70};
    vector<int> arr2={20,10,20,40,50,30,90,80,100,60,70};

    isMinHeap(arr1)?cout<<"Yes":cout<<"NO";
}