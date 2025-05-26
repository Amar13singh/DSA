#include <bits/stdc++.h>
using namespace std;


int maxdepth(string s){
    int maxdepth = 0;
    int depth = 0;

    for(char c:s){
        if(c  == '('){
            depth++;
            maxdepth = max(maxdepth, depth);
        }
        else if(c == ')'){
            depth--;
        }
    }
    return maxdepth;
}

int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    int result = maxdepth(s);
    cout << "Maximum depth: " << result << endl;
    return 0;
}