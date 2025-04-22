#include <iostream>
using namespace std;


//selection sort by recursive method
int select(int arr[],int low,int high){
    int minIndex = low;
    for(int i=low+1;i<=high;i++){
        if(arr[i]<arr[minIndex]){
            minIndex = i;
        }
    }
    swap(arr[low],arr[minIndex]);
    return minIndex;
}

void selectionSort(int arr[],int low,int high){
    int minIndex = select(arr,low,high);
     if(low!=minIndex)
    selectionSort(arr,low+1,high);
}

int main(){
    int arr[] = {2,4,1,6,8,11,5,3,12,7,10,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    selectionSort(arr,0,n-1);
    cout<<"\nSorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Final Complexity:
// Metric	            Recursive Version	      Iterative Version    
// Best Case Time	       𝑂(𝑛2)                       O(n2)
// Average Case Time       𝑂(𝑛2)                       O(n2)	
// Worst Case Time	       𝑂(𝑛2)                       O(n2)
// Best Case Space	       𝑂(𝑛)                        O(1)
// Worst Case Space	      𝑂(𝑛)(recursive)             O(1)(constant)