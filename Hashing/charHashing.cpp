#include<iostream>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
      //precompute
      int hash[26]={0};
    //   int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }

    //queries for the number of occurences
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    while(q--){
        char c;
        cout<<"Enter the character: ";
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }

}
