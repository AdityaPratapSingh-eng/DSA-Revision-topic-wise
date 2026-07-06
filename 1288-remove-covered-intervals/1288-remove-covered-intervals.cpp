class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int m= intervals.size();
        int remaining= 0;
         sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
            int l= intervals[0][0];
            int r= intervals[0][1];
        for(int i=1; i<m; i++){ 
          
            if( r>=intervals[i][1]){
                remaining++;
            }
            else{
                l = intervals[i][0];
                r = intervals[i][1];
            }
            }
        
        return m-remaining;
    }
};