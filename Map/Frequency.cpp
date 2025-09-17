
// https://www.geeksforgeeks.org/problems/find-the-frequency/1
// Map store the unique value with key and pairs , normally used ot count the frequency of a number. 
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
