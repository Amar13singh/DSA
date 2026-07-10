#include <iostream>

using namespace std;

template < class Type >
    void bubbleSort(Type arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
        bool swapDone = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
            Type temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            swapDone = true;
            }
        }
        if (!swapDone) return;
        }
    }
int main() {
    int n = 5;
    int arr1[] = {
    11,
    4,
    9,
    2,
    0
    };
    float arr2[] = {
    3.67,
    9.87,
    1.22,
    2.45,
    4.32
    };


    bubbleSort(arr1, n);
    bubbleSort(arr2, n);
    cout << "Sorting of Integers\n";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\nSorting of Floating Point Numbers\n";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}
