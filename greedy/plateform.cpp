#include <bits/stdc++.h>
using namespace std;
// O(n^2) approach  Time complexity: O(n^2) and space complexity: O(1)  TLE

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int n= arr.size();
         int ans=0;
        for(int i=0; i<n; i++){
            int plateform=1;
            
            for(int j=i+1; j<n; j++){
                 if(arr[i]<= dep[j] && dep[i]>= arr[j]){
                     plateform++;
                 }
            }
            ans= max(ans, plateform);
        }
            return ans;  
    }
};


 // O(nlogn) approach Time complexity: O(nlogn) and space complexity: O(1)
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
           int ans=0;
        int n= arr.size();
            int p=0;
            int i=0, j=0;
            while(i<n && j<n){
                if(arr[i]<= dep[j]){
                    p++;
                    i++;
                }
                else if(arr[i]> dep[j]){
                    p--;
                    j++;
                }
                ans= max(p, ans);
            }
        
            return ans;  
    }
};
