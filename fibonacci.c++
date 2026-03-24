#include<iostream>
#include<vector>
using namespace std;
   // top down approach
   int solve(int n, vector<int>&dp){
    if(n==0)return 0;
    if(n==1)return 1;
   if( dp[n]!=-1)return dp[n];;
    return  dp[n] = (solve(n-1, dp) + solve(n-2, dp));
   }


    // bottom up approach

    int fib(int n) {
        vector<int>dp(n+1, -1);
        dp[0]=0;
        dp[1]= 1;
        for(int i=2; i<=n; i++){
            dp[i]= dp[i-1]+ dp[i-2];
        }

        return dp[n];
    }
      // space optimization  0(1) space complexity
    int constSpace(int n){
        int a=0; 
        int b=1;
        int c;
        for(int i=1; i<n; i++){
             c= a+b;
            a=b;
             b= c;
        }
        return c;
    }



using namespace std;
int main(){
    int n;
     cin>>n;
     vector<int>dp(n+1, -1);;
    cout<< solve(n, dp)<<endl;
        cout<< fib(n)<<endl;
        cout<< constSpace(n)<<endl;


}