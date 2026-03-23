#include<stdio.h>

int max(int *p,int n){
    int a = 0,b = n-1;
    while(a!=b){
        if(p[a]<=p[b]){
            a++;
        }else{
            b--;
        }
        printf("%d %d\n",a,b);
    }
    return p[a];
}
int main(){
    int arr[] = {10,5,6,2,3,6,9,11,7,8,9,1};
    // printf("%d",arr[0]);
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d",max(arr,n));

    return 0;
}