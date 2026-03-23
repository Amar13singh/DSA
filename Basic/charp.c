#include<stdio.h>
 int main(){
    int a = 256;
    char *p;
    p = (char*)&a;
    printf("%d\n",*p);
    return 0;
 }