#include <stdio.h>

int size = 5;
int CQ[5];
int front = -1, rear = -1;


void enqueue(int x) {
  if (front == -1 && rear == -1) {
    front = rear = 0;
    CQ[rear] = x;
    printf("inserted Element is:%d\n", x);
  }
  else if((rear + 1) % 5 == front) {
    printf("Queue is full");
  }
  else {
    rear = (rear + 1)%5;
    CQ[rear] = x;
    printf("inserted Element is:%d\n", x);
  }
}



void dequeue() {
  if (front == -1 && rear == -1) {  // When there is no element in Queue.....
    printf("Queue is empty");
  }

  else if (front == rear) {  //when there us only one element in Queue.....
    printf("deleted Element is:%d\n", CQ[front]);
    front = rear = -1;
  }

  else {
    printf("deleted Element is:%d\n", CQ[front]);
    front = (front + 1) % 5;
  }
}

//   void print() {
//     for(int i=0;i<5;i++) {
//       printf("%d->",CQ[i]);
//     }
//   }


//   void displayQueue() {
//     if (front == -1) {
//       printf("\nQueue is Empty");
//       return;
//     }
//     printf("\nElements in Circular Queue are: ");
//     if (rear >= front) {
//       for (int i = front; i <= rear; i++)
//         printf("%d ", CQ[i]);
//     } else {
//       for (int i = front; i < size; i++)
//         printf("%d ", CQ[i]);

//       for (int i = 0; i <= rear; i++)
//         printf("%d ", CQ[i]);
//     }
//   }
int temp1 = front;
int temp2 = rear;
void displayQueue() {
  while((temp2+1)%size != temp1) {
    
    printf("%d->", CQ[temp1]);
    temp1 = (temp1 + 1) % size;
  }
}

int main() {
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);

  printf("CQ:");
  displayQueue();
  printf("\n");

  dequeue();
  dequeue();

  printf("CQ:");
  displayQueue();
  printf("\n");

  enqueue(1);
  enqueue(2);

  printf("CQ:");
  displayQueue();
  
  
}