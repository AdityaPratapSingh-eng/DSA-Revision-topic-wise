class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n= img1.size();
        int ans=0;
        for(int rowShift=-(n-1); rowShift <= n-1; rowShift++){
         for(int colShift=-(n-1); colShift <= n-1; colShift++){
            int count=0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){

                        if(img1[i][j]==1){
                        int newR= i+rowShift;
                        int newC= j+ colShift;

                        if((newR>=0 && newR<n)&& (newC>=0 && newC <n) && img2[newR][newC]==1){
                       count++;
                        }
                        }
                    }
                }
                ans= max(ans, count);
        }
        }
        return ans;
    }
};