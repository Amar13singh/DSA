#include<iostream>
using namespace std;

void fun(int n,int sum)//parameterized recursion.
{
    if(n==0)
    {
        cout<<"sum is:"<<sum;
        return;
    }
    else {
    {
        fun(n-1,sum+n);
        
    }
    }
}

int main()
{
    int n,sum=0;
    cout<<"Enter the Number:";
    cin>>n;
    fun(n,sum);
}

