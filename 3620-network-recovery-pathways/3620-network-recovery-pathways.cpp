class Solution {
public:
          bool solve(long long safe,  vector<vector<pair<int, int>>>&adj,  vector<bool>& online, long long  k){
                       int n= adj.size();
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
                     vector<long long >dist(n, LLONG_MAX);

                     dist[0]= 0;

                     pq.push({0, 0});

                     while(!pq.empty()){

                        auto [distance, node]= pq.top();
                        pq.pop();

                        if(distance>dist[node]){
                            continue;
                        }
                        if(node== n-1)return distance<= k;

                        for(auto &[nextnode, w]: adj[node]){

                                 if (w < safe)
                                    continue;

                              
                                if (!online[nextnode])
                                   continue;

                                   long long newdist= w+ distance;
                                     
                                   if(newdist< dist[nextnode]){
                                     dist[nextnode]=newdist;
                                     pq.push({newdist, nextnode});
                                   }
                                   
                        }
                     }

                     return false;

          }

   
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n= online.size();

        vector<vector<pair<int, int>>>adj(n);
         long long  high= 0;
        for(auto & a: edges){
            int u= a[0];
            int v= a[1];
            int w= a[2];

            adj[u].push_back({v,w});
            high= max(high, (long long)w);
        }
     
         long long low= 0;
           long long ans=-1;
         while(low<= high){
            long long mid= low + (high- low)/2;

            if(solve(mid, adj, online , k)){
                ans= mid;

                low= mid+1;
            }
            else{
                 high= mid-1;
            }
         }

         return ans;

    }
};