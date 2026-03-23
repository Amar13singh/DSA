#include<stdio.h>
int count = 0;
int power(int a ,int b){
    int y=1;
    while(b>0){
        count++;
        if(b%2==1){
            y=y*a;
            b=b-1;
        }else{
            a=a*a;
            b=b/2;
            
        }
    }
}
int main(){
    int a=2,b=20;
    printf("%d",power(a,b));
    printf("\n%d",count);

}