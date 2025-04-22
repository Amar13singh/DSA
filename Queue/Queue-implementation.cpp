#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
  int arr[MAX_SIZE];
  int front, rear;

public:
  Queue() { front = rear = -1; }

  bool isFull() { return rear == MAX_SIZE - 1; }

  bool isEmpty() { return front == -1; }





  void enqueue(int value) {
    if (isFull()) {
      cout << "Queue is full. Cannot enqueue.\n";
      return;
    }
    if (isEmpty())
      front = 0;
    arr[++rear] = value;
    cout << value << " enqueued to queue.\n";
  }




  int dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty. Cannot dequeue.\n";
      return -1;
    }
    int value = arr[front];
    if (front == rear)
      front = rear = -1;
    else
      front++;
    cout << value << " dequeued from queue.\n";
    return value;
  }

  

  int peek() {
    if (isEmpty()) {
      cout << "Queue is empty. Cannot peek.\n";
      return -1;
    }
    return arr[front];
  }
};


int main() {
  Queue queue;
  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);

  cout << "Front element: " << queue.peek() << endl;

  queue.dequeue();
  queue.dequeue();

  cout << "Front element after dequeuing: " << queue.peek() << endl;

  return 0;
}










