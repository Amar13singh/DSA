#include<bits/stdc++.h>
using namespace std;

vector<int>validSeq(string a,string b){
    int m = a.size(),n = b.size();

    //building suffix array to store last matching index....
    vector<int>suf(n+1,-1);

    for(int i=m-1,j=n-1;i>=0;i--){
        if(a[i]==b[j]) suf[j--] = i;
        if(j<0) break;
    }

    vector<int>res(n);
    bool changed = false;


    //now greedily matching chars..

    for(int i=0,j=0;i<=m;i++){
        if(a[i]==b[j]) res[j++] = i;

        else if(!changed && i<suf[j+1]){
            changed = true;
            res[j++] = i;
        }
        if(j==n) return res;
    }
    return {};
}

int main(){
    // string a = "vabccd";
    string a = "vbccd";
    string b = "abc";

    vector<int>arr = validSeq(a,b);
    for(int x:arr) cout<<x<<" ";
}

// complexity:
     // T(n): O(m+n) or O(m)
    //  S(n): O(n)