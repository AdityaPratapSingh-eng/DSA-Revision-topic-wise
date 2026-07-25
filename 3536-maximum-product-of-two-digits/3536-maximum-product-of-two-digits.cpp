class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
          while(n>0){
            int last= n%10;
            v.push_back(last);

            n/= 10;
          }
        sort(v.begin(), v.end());
          int s= v.size();
        
          return  v[s-1]*v[s-2];
    }
};