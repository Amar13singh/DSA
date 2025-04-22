#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
void merge(int arr[],int left,int mid,int right){
    int i=left,j=mid+1;

    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            i++;
        }
        else{
            int temp = arr[j];
            int k = j;
            while(k>i){
                arr[k] = arr[k-1];
                k--;
            }
            arr[i] = temp;
            i++;
            j++;
            mid++;
        }
    }
}    


void mergeSort(int arr[],int left,int right){
    if(left>=right) return;
    int mid = left + (right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);

}


int main(){
    auto start = high_resolution_clock::now();
    int arr[]= {2,1,8,3,7,4,6,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int left = 0,right = n-1;
    //Array before Sorting
    cout<<"Array before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //Array after sorting....
    mergeSort(arr,left,right);
    cout<<"\nSorted Array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "<<duration.count()<<" microseconds"<<endl;
    return 0;

}