class Solution {
public:

        vector<vector<int>>dir= {{-1,0}, {1,0},{0,1},{0,-1}};


         
          bool canSolve(vector<vector<int>>& dist, int safe) {

        int n = dist.size();

        if (dist[0][0] < safe)
            return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            if(r == n-1 && c == n-1)
                return true;

            for(auto &d : dir) {

                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;

                if(vis[nr][nc])
                    continue;

                if(dist[nr][nc] < safe)
                    continue;

                vis[nr][nc] = true;
                q.push({nr,nc});
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n= grid.size();
         int ans=0;
        queue<pair<int, int>>q;

        vector<vector<int>>dis(n, vector<int>(n, INT_MAX));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    dis[i][j]= 0;

                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            auto [r,c]= q.front();
             q.pop();
            for(auto & d: dir){
                 int nr= r+d[0];
                 int nc= c+ d[1];

               if(nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;

                if(dis[nr][nc] != INT_MAX)
                    continue;

               dis[nr][nc]= dis[r][c]+ 1;

               q.push({nr, nc});
            }
        }
              int l= 0;
            int h= 2*n;

            while(l<=h){
                int mid= l+(h-l)/2;

                if(canSolve(dis, mid)){
                    ans= mid;
                    l= mid+1;
                }

                else{
                    h= mid-1;
                }
            }

       return ans;

    }
};