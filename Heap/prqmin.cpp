#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Min Heap using greater<>
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(17);
    minHeap.push(10);
    minHeap.push(84);
    minHeap.push(19);

    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();//returns the top(min) element
    }
    return 0;
}
