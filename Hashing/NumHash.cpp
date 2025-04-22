#include<iostream>   
using namespace std;

//input  as string can be separated by any symbol.... except space
// input as 1234567890  store as single number 1234567890
//input as 1,2,3,4,5,6,7,8,9,0  store as individual numbers 1,2,3,4,5,6,7,8,9,0 
// here we can use any symbol except number or space
int main(){
    string input;
    cout<<"Enter numbers: ";
    cin>>input;

    //dynamic array implementation
    int* arr=new int[input.length()];
    int index = 0,num=0;

    for(char ch:input){
        if(isdigit(ch)){
            num=num*10+(ch-'0');//convert char to int
        }
        else{
            arr[index++]=num;
            num=0; // Reset num for the next number
        }

}
    // Add the last number to the array
    if(num>0){
        arr[index++]=num;
    }

    //precompute the hash array
    int hash[13]={0}; //assuming the numbers are less than 13
    for(int i=0;i<index;i++){
        hash[arr[i]]++;
    }


    // for(int i=0;i<index;i++){
    //     cout<<arr[i]<<"  ";
    // }


    // queries for the number of occurences
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter the number: ";
        cin>>number;
        cout<<hash[number]<<endl;
    }

    delete[] arr;//free the memory
    return 0;

}

