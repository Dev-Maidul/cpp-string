// https://www.geeksforgeeks.org/problems/word-with-maximum-frequency0120/1
class Solution {
  
    public:
    string maximumFrequency(string &str) {
        // Your code foes here.
       string tmp;
       int maxf=0;
       string ans;
       map<string,int>mp;
       vector<string>v;
       stringstream ss(str);
       while(ss>>tmp)
       {
           mp[tmp]++;
           v.push_back(tmp);
           
       }
       for(auto u:mp)
       {
           maxf=max(maxf,u.second);
       }
       for(auto u: v)
       {
           if(mp[u]==maxf)
           {
               ans=u;
               break;
           }
       }
       return ans + " "+to_string(maxf);
      
       
    }


};