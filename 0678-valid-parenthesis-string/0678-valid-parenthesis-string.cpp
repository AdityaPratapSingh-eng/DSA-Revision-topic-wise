class Solution {
public:   vector<vector<int>>dp;
       bool solve(string &s, int idx, int open){
            if(idx==s.size()){
                return open==0;
            }

               if(open <0)return false;

            if(dp[idx][open]!=-1){
                return dp[idx][open];
            }

         

            if(s[idx]=='('){
             return  dp[idx][open]= solve(s, idx+1, open+1);
              
            }
            else if(s[idx]==')'){
               return dp[idx][open]=  solve(s, idx+1, open-1);
            }

            else{
             return   dp[idx][open]=  solve(s, idx+1, open+1)|| solve(s, idx+1, open-1) ||solve(s, idx+1, open);
            }
       }
    bool checkValidString(string s) {
        int n= s.size();
          dp.assign(n+1, vector<int>(n+1, -1));
            return solve(s, 0,0);
           

            
    }
};