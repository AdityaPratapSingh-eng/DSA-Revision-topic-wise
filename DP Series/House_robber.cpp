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
            cout<<rob(nums);
            return 0;
        }