class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n= arr.size();
        
        int prev2=0;
        int prev= arr[0];
        int temp=0;
        for(int i=2; i<=n; i++){
            int skip= prev;
            int steal= arr[i-1] + prev2;
            
            temp= max(skip, steal);
            prev2= prev;
            prev= temp;
        }
        return temp;
    }
};