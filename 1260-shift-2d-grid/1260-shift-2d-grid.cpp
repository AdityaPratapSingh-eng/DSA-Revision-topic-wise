class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();
           vector<vector<int>>v(m, vector<int>(n,0));
        for(int i=0; i<k; i++){
         
          
            for(int i=0; i<m; i++){
              for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    v[i][j]= grid[m-1][n-1];
                }

                else if(j==0 && i!=0){
                    v[i][j]= grid[i-1][n-1];
                }

                else{ 
                    v[i][j]= grid[i][j-1];
                }

              }
            }
              for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    grid[i][j]= v[i][j];
                }
              }
        }

        return grid;
    }
};