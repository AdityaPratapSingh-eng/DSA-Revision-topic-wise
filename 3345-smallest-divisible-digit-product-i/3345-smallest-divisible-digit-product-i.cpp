class Solution {
public:     
       bool isvalid(int n, int t){
         int pro=1;
           while(n){
              int l= n%10;
              pro*= l;
              n/=10;
           }
           return pro%t== 0;
       }
    int smallestNumber(int n, int t) {
        while(true){
              if(isvalid(n, t)){
                 return n;
              }
              else{
                n++;
              }
        }
        return 0;
    }
};