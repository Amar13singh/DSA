#include<stdio.h>
#include<stdlib.h>
int main(){
    int n = 5;
    int *a = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
    *(a + i) = (i + 1) * 10;
}

for(int i = 0;i<n;i++){
    printf("%d ",a[i]);
}

}