class Solution {

           int m;
           int n;
        
      int  dfs(int [][]grid, int i, int j){
              if(i>=m || j>=n  || i<0 || j<0 || grid[i][j]==0){
                return  0;
              }

             
                   grid[i][j]=0;

              return   1+  dfs(grid,  i+1, j) 
              + dfs(grid,  i, j+1)
               + dfs(grid,  i-1, j)
              +dfs(grid, i, j-1);
                 
              }
    public int maxAreaOfIsland(int[][] grid) {
          m= grid.length;
         n= grid[0].length;
     
        int ans=0;
      
         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                  if( grid[i][j]==1){
                   int a=  dfs(grid, i, j);
                    ans= Math.max(ans, a);
                  }
            }
    }

    return ans;
    }
}
