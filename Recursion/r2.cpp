#include<iostream>
using namespace std;

// void fun(int n,int N)
void fun(int n)
{
    // if(n>N)
    if(n==0)
    {
        return;
    }
    else {
    {
        cout<<n<<" ";// descending order.
        
        fun(n-1);
        
        // fun(n+1,N);
        // cout<<n<<" ";//ascending order.
        
    }
    }
}

int main()
{
    int n;
    cout<<"Enter the Number:";
    cin>>n;
    fun(n);
    // fun(1,N);
}



