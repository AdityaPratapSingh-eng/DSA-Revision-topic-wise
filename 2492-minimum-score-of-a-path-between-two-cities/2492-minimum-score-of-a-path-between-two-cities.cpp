class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
             queue<int>q;
             vector<bool>vis(n+1, false);
            vector<vector<pair<int, int>>>adj(n+1);

            for(auto & a: roads){
                int u= a[0];
                int v= a[1];
                int w= a[2];

                adj[u].push_back({v, w});
                 adj[v].push_back({u, w});

            }
             q.push(1);
             vis[1]= true;
              int ans=INT_MAX;
             while(!q.empty()){
                int curr= q.front();
                q.pop();
                
                 for(auto & v: adj[curr]){
                     int next= v.first;
                     int w= v.second;

                        ans= min(ans, w);
                        if(!vis[next]){
                        vis[next]= true;
                        q.push(next);
                        }
                     
                 }
             }
             return ans;
    }
};