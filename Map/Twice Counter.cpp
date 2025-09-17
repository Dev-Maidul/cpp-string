
//https://www.geeksforgeeks.org/problems/twice-counter4236/1
class Solution {
  public:
    int countWords(string list[], int n) {
        // code here.
        map<string,int>m;
        for(int i=0; i<n; i++)
        {
            m[list[i]]++;
        }
        int ans=0;
        for(pair<string,int> u: m)
        {
            if(u.second==2)
            {
                ans++;
            }
        }
        return ans;
    }
};