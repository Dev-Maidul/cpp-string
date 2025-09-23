//https://basecamp.eolymp.com/en/problems/3966
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin>>n;
    set<int>st;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int y;
        cin>>y;
        if(st.count(y)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}