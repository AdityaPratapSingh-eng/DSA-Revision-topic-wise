class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n= arr.size();
         vector<int>org= arr;

        sort(arr.begin(), arr.end());
        
        unordered_map<int, int>mp;
       mp[arr[0]]=1;
        for(int i=1; i<n; i++){
            if(mp[arr[i]]==0)
             mp[arr[i]]= mp[arr[i-1]]+ 1;
             else
             mp[arr[i]]= mp[arr[i-1]];
        }

         vector<int>ans(n);
        for(int i=1; i<=n; i++){
            ans[i-1]= mp[org[i-1]];
    }
    return ans;
    }
};