class Solution {
public:
       bool dfs(vector<vector<int>>&g, int curr,  vector<bool>&vis, vector<bool>&recPath){
             vis[curr]= true;
            recPath[curr]= true;
             for(auto &v : g[curr]){
                if(vis[v]==false){
                    if(dfs(g, v, vis,  recPath)){
                        return true;
                    } 
                }
                else if(recPath[v]){
                    return true;
                }
             }
             recPath[curr]= false;

             return false;
       }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n= numCourses;
        vector<vector<int>>g(n);

        for(int i=0; i<prerequisites.size(); i++)
        {
            int b= prerequisites[i][1];
            int a= prerequisites[i][0];
            g[a].push_back(b);

        }
       
        vector<bool>vis(n ,false);
         vector<bool>recPath(n,  false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
             if( dfs(g, i, vis, recPath)){
                   return false;
             }
            }
        }
        return true;
    }
};