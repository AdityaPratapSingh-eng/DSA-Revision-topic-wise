class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n= arr.size();

        
         int i=0;
         int sum=0;
         int res= INT_MAX;
          int minLen= INT_MAX;
          vector<int>minLenarrTilli(n+1, INT_MAX);
         for(int j=0; j<n; j++){
              sum+= arr[j];
              
              while(sum>target){
                  sum-= arr[i];
                  i++;
              }
               if(sum==target){
                    int len= j-i+1;
                   if(i>0 && minLenarrTilli[i-1]!= INT_MAX){
                    res= min(res, len+ minLenarrTilli[i-1]);
                   }
                    minLen= min(minLen, len);
               }

                if (j > 0) {
                minLenarrTilli[j] = min(minLenarrTilli[j - 1], minLen);
            } else {
                minLenarrTilli[j] = minLen;
            }
             
         }
         return ( res == INT_MAX)? -1 : res;
    } 
};