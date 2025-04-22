// insertion Sort:-- 

#include<iostream>
using namespace std;
#include<ctime>
#include<chrono>
using namespace std::chrono;

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        // int key = arr[i];
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
            else{
                break;
            }
        }

    }
}

int main(){

    //  start = clock();
    auto start = high_resolution_clock::now();
    int arr[] = {2,4,1,6,8,11,5,3,12,7,10,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    insertionSort(arr,n);
    cout<<"\nSorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}