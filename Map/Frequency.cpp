
class Solution {
  public:
    int findFrequency(vector<int> arr, int x) {
        // Your code here
        map<int,int>m;
        for(auto u:arr)
        {
            m[u]++;
        }
        return m[x];
    }
};
