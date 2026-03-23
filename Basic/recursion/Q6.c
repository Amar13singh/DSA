#include<stdio.h>


int f(int n){
    if(n==0) return 1;
    int x=0;
    for(int i=0;i<n;i++)
        x += f(n-1) + f(n-2);
    return x;
}


int main(){
    int n = 4;
    // f(n);
    printf("\nvalue is: %d",f(1));
    return 0;
}

