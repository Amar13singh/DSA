#include<bits/stdc++.h>
using namespace std;


double medianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int i = 0,j = 0;
    int count = 0;
    int index1 = (n1 + n2) / 2;
    int index2 = index1- 1;
    int m1 = -1, m2 = -1;
    while(i<n1 && j<n2){
        if(nums1[i] < nums2[j]){
            if(count == index1) m1 = nums1[i];
            if(count == index2) m2 = nums1[i];
            count++;
            i++;
        }
        else{
            if(count == index1) m1 = nums2[j];
            if(count == index2) m2 = nums2[j];
            count++;
            j++;
        }
    }
    while(i<n1){
        int val = nums1[i++];
        if(count == index1) m1 = val;
        if (count == index2) m2 = val;
        count++;
    }

    while(j<n2){
        int val = nums2[j++];
        if(count == index1) m1 = val;
        if (count == index2) m2 = val;
        count++;
    }
    if((n1 + n2) % 2 == 1) return m1;

    return double(double((m1 + m2))/2);
}
    
int main(){
    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 6, 8, 10};
    double median = medianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;
    return 0;   
}
// Time Complexity: O(m + n)
// Space Complexity: O(1)