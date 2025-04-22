#include<stdio.h>
#include<stdlib.h>

int main(){
    int *a =(int*)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++){
        a[i] = i;
    }
    int b[5];
    b=a;
    printf("%d",b[0]);
}