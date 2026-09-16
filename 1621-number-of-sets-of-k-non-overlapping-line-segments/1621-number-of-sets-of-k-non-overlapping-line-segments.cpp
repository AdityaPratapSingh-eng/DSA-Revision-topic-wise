class Solution {
public:   
     int M= 1e9+7;
     int t[1001][1001];
    int numberOfSets(int n, int K) {
           for(int i=0; i<n; i++){
            t[0][i]= 1;
           }

           for(int k=1;  k<=K; k++){
              vector<int>prevSum(n+1, 0);
              for(int x=n-1; x>=0; x--){
                  prevSum[x]= (prevSum[x+1]+ t[k-1][x])%M;
              }
            for(int i=n-1; i>=0; i--){
               
                long long take= prevSum[i+1];
                long long skip = t[k][i+1];
                t[k][i]= (take+ skip)%M;
            }
           }

           return t[K][0];
    }
};