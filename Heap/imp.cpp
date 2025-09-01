#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (2*i + 1 < n) {
            int smallest = i;
            int l = 2*i + 1, r = 2*i + 2;
            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;
            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
/*************  ✨ Windsurf Command ⭐  *************/
    /**
     * Inserts the given value into the heap.
     *
     * Time complexity: O(log n)
     *
     * @param val the value to be inserted
     */
/*******  3323135b-621e-4bf1-8405-d01590000589  *******/    
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    
    /**
     * Returns the minimum value of the heap. If the heap is empty, returns -1.
     *
     * Time complexity: O(1)
     *
     * @return the minimum value of the heap, or -1 if the heap is empty
     */
    int getMin() {
        return heap.empty() ? -1 : heap[0];
    }

    void removeMin() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(5); h.insert(3); h.insert(17); h.insert(10); h.insert(84); h.insert(19);
    h.printHeap();
    h.removeMin();
    h.printHeap();
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(n)