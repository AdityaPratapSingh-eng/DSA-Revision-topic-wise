class Solution {
public:        vector<vector<bool>>vis;
             bool isValid(int i, int j, int m, int n, vector<vector<int>>&grid){
                  if(i>=m || j>=n || i<0 || j<0 ||grid[i][j]==0 || vis[i][j]){
                      return false;
                  }
                  return true;
             }

             int direction[4][2]= {{-1,0},{1,0},{0,1},{0,-1}};
            long long  bfs(vector<vector<int>>&grid, int i, int j, int m, int n){
                    queue<pair<int, int>>q;
               long long  ans=0;
                    q.push({i, j});
                    vis[i][j]= true;

                    while(!q.empty()){
                        auto curr= q.front();
                        q.pop();
                        int x= curr.first;
                        int y= curr.second;

                        ans+= grid[x][y];

                        for(const auto &dir: direction){
                            int newx= x+ dir[0];
                            int newy= y+ dir[1];

                            if(isValid(newx, newy, m, n, grid)){
                                q.push({newx, newy});
                                vis[newx][newy]= true;
                            }
                        }
         
                    }
                        return ans;
            }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();
        vis.resize(m, vector<bool>(n, false));
         int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                  if(grid[i][j]!=0 && (!vis[i][j])){
                    long long val=  bfs(grid, i, j, m, n);
                    if( val >0 && val%k==0)ans++;
                  }
            }
        }
        return ans;
    }
};