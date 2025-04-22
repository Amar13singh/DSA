#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;



void merge(int arr[],int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right-mid;

    int arr1[n1],arr2[n2];


    for(int i=0;i<n1;i++){
        arr1[i] = arr[left+i];
    }
    for(int j=0;j<n2;j++){
        arr2[j] = arr[mid+1+j];
    }

    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k] = arr1[i];
            i++;k++;
        }
        else{
            arr[k] = arr2[j];
            j++;k++;
        }
        
}
//copying remaining elements of arr1 and arr2
//its good but not efficient as it wont work for all cases...

// if(i<=n1 && j<=n2){
//     if(i<n1){
//         arr[k] = arr1[i];
//     }
//     else{
//         arr[k] = arr2[j];
//     }
// }
//copying remaining elements of arr1
while(i<n1) arr[k++] = arr1[i++];
//copying remaining elements of arr2
while(j<n2) arr[k++] = arr2[j++];

}


void mergeSort(int arr[],int left,int right){
    int mid = left+(right-left)/2;//to avoid overflow
    if(left>=right) {
        return;
    }
    else{
    // int mid = (left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);

    }

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
    
    cout<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time Taken by Function:"<<duration.count()<<"microseconds"<<endl;

}