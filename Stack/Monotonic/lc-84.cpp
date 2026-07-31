//largest rectangle area...

#include<bits/stdc++.h>
using namespace std;

int maxRect(vector<int>& h){
    int n = h.size();
    stack<int>st;

    int ans = 0;

    for(int i=0;i<=n;i++){
        while(!st.empty() && 
        (i==n || h[st.top()] >= h[i])){
            
            int ht = h[st.top()];
            st.pop();

            int wt = st.empty()?i:i-st.top()-1;
            
            ans = max(ans,ht*wt);
        }
        st.push(i);
    }
    return ans;
}


int main(){
    vector<int> arr = {2,1,5,6,2,3};
    cout<<"Maximum Area is: "<<maxRect(arr);

}

