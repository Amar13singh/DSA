#include<iostream>
using namespace std;

void fun(int n)
{
    if(n==0)
    {
        return;
    }
    else {
    {
        fun(n-1);
        cout<<n<<" ";
        fun(n-1);
        cout<<n<<" ";
    }
    }
}

int main()
{
    int n;
    cout<<"Enter the Number:";
    cin>>n;
    fun(n);
}



