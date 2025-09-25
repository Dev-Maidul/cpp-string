//https://codeforces.com/problemset/problem/22/A
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set < int > st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    if(st.size()==1) cout<<"NO\n";
    else cout<<*++st.begin()<<endl;

}