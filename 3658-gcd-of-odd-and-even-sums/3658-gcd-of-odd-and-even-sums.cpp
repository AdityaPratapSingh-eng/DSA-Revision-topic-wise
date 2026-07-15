class Solution {
public:
    int gcdOfOddEvenSums(int n) {
      int sumEven=2;
      int sumOdd= 1;
      int ans1=0, ans2=0;
        for(int i=1; i<=n; i++){
           ans1+=sumEven;
           sumEven+=2;

           ans2+= sumOdd;
           sumOdd+=2;
        }
        return __gcd(ans1, ans2);
    }
};