// https://codeforces.com/problemset/problem/520/A
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	set<char>st;
	for(int i=0; i<n; i++)
	{
	    char c;
	    cin>>c;
	    c=tolower(c);
	    st.insert(c);
	}
	if(st.size()==26) cout<<"YES\n";
	else cout<<"NO\n";

}
