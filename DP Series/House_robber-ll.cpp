 #include <bits/stdc++.h>
using namespace std;

             int t[101];
          int solve(vector<int>& nums, int i, int n){

            if(i>n)return 0;

            if(t[i]!=-1)return t[i];

            int take=  nums[i] + solve(nums, i+2, n);
            int skip= solve(nums, i+1, n);

            return t[i]= max(take, skip);
          }
          // top- down approachh (recursion + memoization)
    
    int rob(vector<int>& nums) {
          int n= nums.size();

          if(n==1)return nums[0];
          if(n==2)return max(nums[0], nums[1]);
          memset(t, -1, sizeof(t));
          // case-1   take 0th:
         int take= solve(nums, 0, n-2);

         memset(t, -1, sizeof(t));
         // case -2  skip 0th
         int skip= solve(nums, 1, n-1);

         return max(take, skip );
    }
        int main(){
            int n;
            cin>>n;
            vector<int>nums(n);
            for(int i=0; i<n; i++){
                cin>>nums[i];
            }


           

          // bottom up approach (tabulation)
       if(n==1)return nums[0];
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=0;
        // case- 1 skip first house
        for(int i=2; i<=n; i++){
             int take= nums[i-1]+ (i-2>=0 ? dp[i-2] : 0);
             int skip = dp[i-1];

             dp[i]= max(take, skip);
        }
        int ans1= dp[n];
        dp.clear();

        dp[0]=0;
         //case- 2 skip first house
        for(int i=1; i<=n-1; i++){
             int take= nums[i-1]+ (i-2>=0 ? dp[i-2] : 0);
             int skip = dp[i-1];

             dp[i]= max(take, skip);
        }
        int ans2= dp[n-1];

        cout<<" bottom-up " << max(ans1, ans2) << endl;

            cout<<rob(nums);
            return 0;
        }   