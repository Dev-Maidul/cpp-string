//https://www.hackerrank.com/challenges/cpp-sets/problem
#include <bits/stdc++.h>

using namespace std;

int main() {

    int q;
    cin >> q;
    set<int>st;
    while(q--)
    {
        int type,x;
        cin>>type>>x;
        if(type==1)
        {
            st.insert(x);
        }
        else if(type==2)
        {
            st.erase(x);
        }
        else{
            if(st.count(x)){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
        
    }

}