#include <bits/stdc++.h>

using namespace std;

int main() {
    // set must be unique and sorted
    // set all operation complexity O(log n);

    // insert value on set 
    set<int>st;
    st.insert(1);
    st.insert(2);
    st.insert(2);
    	for(auto v:st) {
    	    cout<<v<<endl;
    	}
    // print for size
    cout << "Size= " << st.size()<<endl;
    // checking empty or not 
    cout<<"empty= "<<st.empty()<<endl;
    // clear the set
    // s.clear();
    //  cout << "Size= " << s.size()<<endl;
    //   // checking empty or not 
    // cout<<"empty= "<<s.empty()<<endl;
    // erase value from set 
    st.erase(2);
    
    // to check whether the value exist or not in set 
    if(st.count(1))
    {
        cout<<"yes\n";
    }
    else cout<<"no\n";
    
    // find method return the pointer of set
     // if value not availbe in set then it will return the end pointer of set 
     if(st.find(10)== st.end()){
         cout<<"Not Exist\n"; // not exist
     }
     else cout<<"Exist\n";
     // for descending order 
    set<int,greater<int>>s;
    s.insert(1);
     s.insert(2);
      s.insert(3);
       s.insert(5);
       for(auto u:s) cout<<u<<endl;

    return 0;
}