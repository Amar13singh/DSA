#include<iostream>
// #include<E:\CSE\Dsa\swap.cpp>
using namespace std;


int main(){
    int sort[4] = {3,2,1,4};
    int n=3;
    for(int i=0;i<n;i++){
        for(int j= 0;j<(n-i);j++){
        if(sort[j]>sort[j+1]){
            // swap(sort[j],sort[j+1]);
            int temp = sort[j];
            sort[j]=sort[j+1];
            sort[j+1]=temp;
        }
    }
}
cout<<"sorted array is:";
for(int i=0;i<4;i++){
    cout<<sort[i]<<",";
}
}





