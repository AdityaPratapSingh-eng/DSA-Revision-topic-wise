class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n= nums.size();

        int mx= *max_element(nums.begin(),nums.end());
      int t=1;
      while(t<= mx){
        t*=2;
      }
        vector<bool>v1(t, false);

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int pair= nums[i]^nums[j];

                v1[pair]= true;
        }
        }

        vector<bool> v2(t, false);
          int count=0;
        for(int i=0; i<v1.size(); i++){
            if(v1[i]){
          for(int j=0; j<n; j++){
                  int xr= nums[j]^ i;
                   v2[xr]=true;
            }

            }
            }
        
        for(int i=0; i<t; i++){
            if(v2[i]){count++;}
        }


        return count;
    }
};