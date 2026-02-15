#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        int cst=intervals[0][0];
        int cend=intervals[0][1];
        int n= intervals.size();
        for(int i=1; i<n; i++){
           int nextSt= intervals[i][0];
           int nextEd= intervals[i][1];
           if(nextSt<=cend){
            cend= max(cend, nextEd);
           }
           else{
             ans.push_back({cst, cend});
             cst= intervals[i][0];
             cend= intervals[i][1];
           }
        }
        ans.push_back({cst, cend});
          
       return ans;
    }
};
