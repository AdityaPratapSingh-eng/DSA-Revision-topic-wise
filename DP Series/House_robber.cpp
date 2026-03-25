 #include <bits/stdc++.h>
using namespace std;

        int t[101];
         // top down Approach (recursion + memoization)
        int solve(vector<int>& nums, int i){
            if(i>= nums.size()){
                return 0;
            }

            if(t[i]!= -1)return t[i];

            int take= nums[i]+ solve(nums, i+2);
            int skip= solve(nums, i+1);

            return  t[i]= max(take, skip);

            
        }


        // bottom up approach (tabulation)
        
    int bottom_Up(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1, 0);

        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2; i<=n; i++){
            int take= nums[i-1]+ dp[i-2];
            int skip= dp[i-1];

            dp[i]= max(take, skip);
        }
        return dp[n];
    }


    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0);
    }
        int main(){
            int n;
            cin>>n;
            vector<int>nums(n);
            for(int i=0; i<n; i++){
                cin>>nums[i];
            }

            cout<<bottom_Up(nums)<<endl;
            cout<<rob(nums);
            return 0;
        }