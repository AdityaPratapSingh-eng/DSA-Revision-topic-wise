class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size();

        int left=0;
        int ans=0;
     vector<int>v(3,0);
        for(int i=0; i<n; i++){
           v[s[i]-'a']++;

           while(v[0]>0 && v[1]>0 && v[2]>0){

            ans+= n- i;

            v[s[left]- 'a']--;
            left++;
           }
        }
        return ans;
    }
};