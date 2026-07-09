class Solution {
public:
         typedef  long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
         int n= s.size();
        int MOD= 1000000007;
         vector<int>sumUpto(n,0 );
         vector<ll>nonZero(n, 0);
         vector<ll>numberUpto(n, 0);
         vector<ll>pok(n+1, 0);

         pok[0]=1;
         for(int i=1; i<=n; i++){
            pok[i]= (pok[i-1] * 10)%MOD;
         }

         nonZero[0]= (s[0]=='0')?0: 1;
         for(int i=1; i<n; i++){
           if(s[i]=='0'){
              nonZero[i]= nonZero[i-1];
           }
           else{
             nonZero[i]= nonZero[i-1]+ 1;
           }
         }

         sumUpto[0]= s[0]- '0';
         for(int i=1; i<n; i++){
            int digit= s[i]-'0';
            sumUpto[i]= sumUpto[i-1]+(digit);
         }

         numberUpto[0]= s[0]-'0';
         for(int i=1; i<n; i++)
         {  int digit= s[i]-'0';
           if(s[i]!='0'){
             numberUpto[i]= (numberUpto[i-1]*10+ digit)%MOD;
           }
           else{
            numberUpto[i]=  numberUpto[i-1];
           }
         }


         int q= queries.size();
         vector<int>ans(q, 0);
         for(int i=0; i<q; i++){
            int l= queries[i][0];
            int r= queries[i][1];

            ll sum= sumUpto[r]- ((l==0)? 0: sumUpto[l-1]);
            int k= nonZero[r]- ((l==0)?0: nonZero[l-1]);
            int numbefore= ((l==0)? 0: numberUpto[l-1]);
            ll x= (numberUpto[r]- (numbefore*pok[k]%MOD)+MOD)%MOD;

           ans[i]= int((sum*x)%MOD);
         }

        return ans;
    }
};