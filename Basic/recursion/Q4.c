#include<stdio.h>

int count = 0;
void get(int n){
    count++;
    printf("%d ",n);
    if(n<1) return;
    get(n-1);
    get(n-3);
    // printf("%d ",n);

}
int main()
{
    int n = 6;
    get(n);
    printf("\nCount is: %d",count);
    return 0;
}