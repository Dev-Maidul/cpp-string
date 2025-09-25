// https://codeforces.com/problemset/problem/469/A
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	set<int>level;
	int x;
	cin>>x;
	for(int i=0; i<x; i++)
	{
	    int a;
	    cin>>a;
	    level.insert(a);
	}
	int y;
	cin>>y;
	for(int i=0; i<y; i++)
	{
	    int a;
	    cin>>a;
	    level.insert(a);
	}
	if(level.size()==n) cout<<"I become the guy.\n";
	else cout<<"Oh, my keyboard!\n";

}
