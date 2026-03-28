class Solution {
  public:
          int solve(vector<int>& arr,  int l, int r){
              int prev=0;
              int prev2=0;
              int temp;
              for(int i=l; i<=r; i++){
                  int skip= prev;
                  int take= arr[i]+ prev2;
                  
                  temp = max(skip, take);
                  
                  prev2= prev;
                  prev= temp;
              }
              return prev;
          }
  
     
    int maxValue(vector<int>& arr) {
        // code here
      int n= arr.size();
      if(n==2)return max(arr[0] , arr[1]);
      
     int take_0= solve(arr,0, n-2);
     int skip_0= solve(arr, 1, n-1);
     
     return max(take_0, skip_0);
    }
};
