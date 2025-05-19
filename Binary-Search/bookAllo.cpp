#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPossible(vector<int>& arr, int m, int maxPages) {
        int students = 1;
        int pagesSum = 0;

        for (int pages : arr) {
            if (pagesSum + pages <= maxPages) {
                pagesSum += pages;
            } else {
                students++;
                pagesSum = pages;
                if (students > m) return false;
            }
        }

        return true;
    }

    int allocateBooks(vector<int>& arr, int m) {
        if (m > arr.size()) return -1; // Not enough books

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, m, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {12, 34, 67, 90};
    int m = 2;
    int result = solution.allocateBooks(arr, m);
    cout << "The minimum number of pages allocated to a student is: " << result << endl;
    return 0;
  }

  
  //Time Complexity: O(N*log(sum(arr[])))
  //Space Complexity: O(1)