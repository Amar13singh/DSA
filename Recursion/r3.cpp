#include<iostream>
using namespace std;

int count=0;
// void fun(int n)
int fun(int n)
{
    if(n==0)
    {
        // return ;
        return 0;
    }
    else {
    {
              //first method.

        // fun(n-1);
        // cout<<n<<" ";
        // count=count+n;



        //2nd method.
        return n+fun(n-1);


        
    }
    }
}

int main()
{
    int n;
    cout<<"Enter the Number:";
    cin>>n;
    // fun(n);
    // cout <<"\n Sum is:"<<count;
    cout<<fun(n);
}



