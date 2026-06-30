#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
private:

    vector<int> heap;

    int parent(int i){
        return (i - 1) / 2;
    }

    int left(int i){
        return 2 * i + 1;
    }

    int right(int i){
        return 2 * i + 2;
    }

    void heapifyUp(int index){
        while(index > 0 && heap[parent(index)] < heap[index]){
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index){
        int n = heap.size();

        while(true){
            int largest = index;
            int l = left(index);
            int r = right(index);

            if(l < n && heap[l] > heap[largest]) largest = l;

            if(r < n && heap[r] > heap[largest]) largest = r;

            if(largest == index) break;

            swap(heap[index], heap[largest]);

            index = largest;
        }
    }

public:

    void push(int value){
        heap.push_back(value);

        heapifyUp(heap.size() - 1);
    }

    void pop(){
        if(heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty())
            heapifyDown(0);
    }

    int top(){
        if(heap.empty())
            throw runtime_error("Heap Empty");

        return heap[0];
    }

    bool empty(){
        return heap.empty();
    }

    int size(){
        return heap.size();
    }

    void print(){
        for(int x : heap)
            cout << x << " ";
        cout << '\n';
    }
};

//Driver code.....

int main()
{
    MaxHeap h;

    vector<int> nums ={ 40,70,20,100,10,90,80,60,50,30 };

    cout << "Insertion:\n";

    for(int x : nums){
        h.push(x);
        h.print();
    }

    cout << "\nTop = " << h.top() << "\n\n";

    cout << "Deletion:\n";

    while(!h.empty()){
        cout << h.top() << " ";

        h.pop();
    }
}