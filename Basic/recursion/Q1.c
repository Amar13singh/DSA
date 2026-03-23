#include<stdio.h>

int count = 0;
int f(int n) {
    count++;
    printf("%d ",n);
    if(n <= 1) return 1;
    // printf("%d\n ",n);
    return f(n-1) + f(n-2);
}

int main(){
    int n = 5;
    // int count = 0;
    // scanf("%d",&n);
    printf("\nValue is %d",f(n));
    printf("\nCount is %d",count);
    return 0;

}