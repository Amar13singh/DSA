#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

// int arr[] = {2,4,1,6,8,11,5,3,12,7,10,9};
int partition(int arr[],int low,int high){
    int randomIndex = rand()%(high-low+1)+low;
    swap(arr[randomIndex],arr[high]);
    int pivot = arr[high];
    // int pivot = arr[randomIndex];
    int i =low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            if(i!=j){
                swap(arr[i],arr[j]);
            }
        }
    }
    // swap(arr[i+1],arr[high]);//to put pivot at its correct position
    if(i+1!=high){
        swap(arr[i+1],arr[high]);
    }

    return i+1;

}

//function to perform quick sort
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivotIndex = partition(arr,low,high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}


int main(){

    auto  start = high_resolution_clock::now();
    int arr[] = {2,4,1,6,8,11,5,3,12,7,10,9,11,16,13,15,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    quickSort(arr,0,n-1);
    cout<<"\nSorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

}