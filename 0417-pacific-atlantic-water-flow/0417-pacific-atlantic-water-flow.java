class Solution {
            int[][] direction = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

      boolean bfs(int[][] grid, int i, int j, int m, int n, boolean[][]vis){
           Queue<int[]>q= new LinkedList<>();

           q.offer(new int[]{i,j});
            vis[i][j]= true;
              boolean p= false;
                boolean a= false;

            while(!q.isEmpty()){
                int[]curr= q.poll();
                int x= curr[0];
                int y= curr[1];
              
                for(int []dir : direction){
                     int newx= curr[0]+ dir[0];
                     int newy= curr[1]+ dir[1];
                       if(newx<0 || newy<0){
                          p= true;
                          continue;
                       }
                         if(newx>=m || newy>=n){
                          a= true;
                          continue;
                       }

                    if (!vis[newx][newy] &&
                    grid[newx][newy] <= grid[x][y]) {

                    q.offer(new int[]{newx, newy});
                    vis[newx][newy] = true;
                }
                }

              
            }

              return p && a;
          
      }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m= heights.length;
        int n= heights[0].length;
     List<List<Integer>>ans= new ArrayList<>();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                boolean [][]vis = new boolean[m][n];

                if(bfs(heights, i, j, m, n, vis)){
                    List<Integer>ls= new ArrayList<>();
                    ls.add(i);
                    ls.add(j);
                     ans.add(ls);
                }
            }
        }
        return ans;
    }
}
