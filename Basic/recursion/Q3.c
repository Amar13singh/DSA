#include<stdio.h>

int fun(int n)
{
    int x = 0;
    while(n>0)
    {
        x = x+fun(n--);
    }
    return x;

}
int fun1(int n) {
    int x = 0;
    printf("loop  ");
    while(n>0)
    {
        x = x+fun1(n-1);
    }
    return x;
}
int main()
{
    int n = 5;
    // printf("%d",fun(n));
    // printf("%d",fun1(n));
    return 0;
}