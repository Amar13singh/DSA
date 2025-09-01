#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap; // Max Heap (default)
    maxHeap.push(19);
    maxHeap.push(84);
    maxHeap.push(10);
    maxHeap.push(17);
    maxHeap.push(5);
    maxHeap.push(3);

    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    return 0;
}
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
