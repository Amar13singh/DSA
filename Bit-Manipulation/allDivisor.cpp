#include<bits/stdc++.h>
using namespace std;

void Divisor(int n){
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<i<<" ";
            if(i!=n/i) cout<<n/i<<" ";
        }
    }
}

int main() {
    int n = 100;
    cout << "Divisors of " << n << ": ";
    Divisor(n);
    cout << endl;
    return 0;
}