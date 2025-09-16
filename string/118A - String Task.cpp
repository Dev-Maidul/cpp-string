#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
bool isVower(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}
int main()
{
    // to stop flash
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // main code start from here
    
    string str;
    cin>>str;
    string ans="";
    for(auto u:str)
    {
       u=tolower(u);
        if(isVower(u)) continue;
        else{
            ans+=".";
            ans+=u;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}