class Solution {
public:
    int longestValidParentheses(string s) {
      int n= s.size();
      int ans=0;
      for(int i=0; i<n; i++){
        int valid=0;
        for(int j=i; j<n; j++){

            if(s[j]=='('){
                valid++;
            }
            if(s[j]==')'){
                valid--;
            }
             if(valid <0)break;
               

                if(valid==0 ){
                    ans= max(ans, j-i+1);
                }
        }
      }
      return ans;
    }
};