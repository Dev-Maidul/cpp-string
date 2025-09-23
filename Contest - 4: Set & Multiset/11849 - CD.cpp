// https://vjudge.net/contest/676312#problem/E
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
        {
            break;
        }
        set<int>st;
        int count=0;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            st.insert(x);
        }
        for(int i=0; i<m; i++)
        {
            int x;
            cin>>x;
            if(st.count(x)) count++;
        }
        cout<<count<<endl;
    }
}