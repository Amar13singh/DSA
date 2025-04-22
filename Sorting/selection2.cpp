#include<iostream>
using namespace std;


void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minIndex = i;
        //loop to find the minimum element in the unsorted part of the array
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        //swap the minimum element with the first element of the unsorted part
        // swap(arr[i],arr[minIndex]);
        //if we swap without checking it may swap even if sorted so we can check if it is already sorted or not
        if(i!=minIndex){
            swap(arr[i],arr[minIndex]);
        }
    }
}
int main(){
    int arr[] = {2,4,1,6,8,11,5,3,12,7,10,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    selectionsort(arr,n);
    cout<<"\nSorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

