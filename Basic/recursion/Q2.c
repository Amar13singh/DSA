#include<stdio.h>

int count = 0;
int f(int n) {
    count++;
    printf("%d ",n);
    if (n <= 0) return 1;
    return f(n-1) + f(n-2) + f(n-3);
}


int main(){
    int n = 6;
    // int count = 0;
    // scanf("%d",&n);
    printf("\nValue is: %d",f(n));
    printf("\nCount is: %d",count);
    return 0;

}