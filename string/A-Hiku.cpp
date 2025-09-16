#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
bool isVowel(char c)
{
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    else return false;
}
int vowelCount(string s)
{
    int count=0;
    for(auto c: s)
    {
        if(isVowel(c)) count++;
       
    }
     return count;
}
int main()
{
    // to stop flash
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // main code start from here
    
    string s1,s2,s3;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    if(vowelCount(s1)==5 && vowelCount(s2)==7 && vowelCount(s3)==5)
    {
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    
    return 0;
}