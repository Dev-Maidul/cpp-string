#include <bits/stdc++.h>

using namespace std;

int main() {

    string sentence;
    set<string>st;
    while(getline(cin,sentence))
    {
        if(sentence=="#") break;
        stringstream ss(sentence);
        string word;
        while(ss>>word)
        {
            st.insert(word);
        }
    }
    cout<<st.size()<<endl;



    return 0;
}