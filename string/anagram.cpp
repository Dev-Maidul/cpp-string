#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
int main()
{
    // to stop flash
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Anagram called two  string have same number of charecter then it call anagram string
    string s1="listent";
    string s2="listent";
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2) cout<<"Anagram\n";
    else cout<<"Not Anagram\n";

    return 0;
}