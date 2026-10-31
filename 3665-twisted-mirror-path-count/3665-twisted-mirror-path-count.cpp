class Solution {
public:
        const int M= 1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
          int m= grid.size();
          int n= grid[0].size();
             int left=0;
             int up=1;
          vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(2)));
               dp[0][0][left]=1;
               dp[0][0][up]=1;
          for(int c=1; c<n; c++){
               dp[0][c][left]= 1;

               if(grid[0][c]==1){
                break;
               }
          }

          for(int r=1; r<m; r++){
               dp[r][0][up]= 1;

               if(grid[r][0]==1){
                   break;
               }
          }

          for(int r=1; r<m; r++){
            for(int c=1; c<n; c++){
                  if(grid[r][c-1]==1){

                     dp[r][c][left]= dp[r][c-1][up];
                  }
                  else{
                     dp[r][c][left]= (dp[r][c-1][up]+ dp[r][c-1][left])%M;
                  }

                    if(grid[r-1][c]==1){

                     dp[r][c][up]= dp[r-1][c][left];
                  }
                  else{
                     dp[r][c][up]= (dp[r-1][c][up]+ dp[r-1][c][left])%M;
                  }
            }
          }

          return (dp[m-1][n-1][up]+ dp[m-1][n-1][left]) %M;
    }
};