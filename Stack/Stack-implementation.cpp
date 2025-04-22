// #include <climits>//bcz use of int_min

// stack.....last in first out......
// stack using array........
#include <iostream>
using namespace std;
#define MAX_SIZE 100
int stack[MAX_SIZE];
// int stack[10];
int top = -1;

void push(int x) {
  if(top == MAX_SIZE - 1) {
    cout << "Error: Stack overflow\n";
    return;
  }
  top++;
  stack[top] = x; // pushing element into stack
  
  cout << "pushed element is: " << x << endl;
}
//stack should be full otherwise pop operation will cause error
void pop() {
  if(top == -1) {
    cout << "Error: No element to pop\n";
    return ;
  }
  cout << "popped element is " << stack[top] << endl;
  int temp = stack[top];
  top--;
//   return temp;
}
// int n = top;


int main(){
  int a, b, c, d, e;
 
  cout << "Enter the element to be pushed into stack:";
  cin >> a >> b >> c >> d >> e;
  push(a);
  push(b);
  push(c);
  push(d);
  push(e);
  pop();
  pop();
  pop();
  for(int i = 0;i<top+1;i++) {
    
    cout<<"Remain Element is:"<<stack[i]<<"\n";
  }
  

}