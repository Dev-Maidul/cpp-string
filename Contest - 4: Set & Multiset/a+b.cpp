#include <bits/stdc++.h>
// https://vjudge.net/contest/676312#problem/B
using namespace std;

int main() {
    int n, m;
   
    while (cin >> n >> m)
    {
        
        set < int > a;
        // 	set<int>b;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.insert(x);

        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            a.insert(x);

        }
        for (auto u: a)
        {
            cout << u << " ";
        }
        cout<<endl;
    }
}