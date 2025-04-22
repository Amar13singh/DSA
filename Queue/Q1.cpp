#include <iostream>
using namespace std;
#define MAX_SIZE 100

int arr[MAX_SIZE];
int rear;
int front = rear = -1;

bool isFull() {
  return rear == MAX_SIZE - 1;
  }

bool isEmpty() {
  return front == -1;

  }

void inQueue(int x) {
  if (isFull()) {
    cout << "Queue is full. Cannot enqueue.\n";
    return;
  }
  if (front == -1) {
    front = 0;
  }

  arr[++rear] = x; // inserting element in queue.
  cout << x << " enqueued to queue.\n";
}

void deQueue() {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot dequeue.\n";
    return;
  }
  int value = arr[front];
  if (front == rear) {
    front = rear = -1;
  } else {
    front++;
    cout << value << " dequeued from queue.\n";
  }
}
int main() {
  int a, b, c, d, e;
  cout << "Enter the element to be enqueued:";
  cin >> a >> b >> c >> d >> e;
  inQueue(a);
  inQueue(b);
  inQueue(c);
  inQueue(d);
  inQueue(e);
  deQueue();
  deQueue();
  deQueue();
  return 0;
}



