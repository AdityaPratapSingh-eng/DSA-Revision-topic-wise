class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        long ans=0;
         int comma= 1;
         long  st= 1000;
        while(st<= n){
          long  end=  st*1000 -1;
              if(end >n)end =n;

            ans+= (end- st+1)*comma;

            st= st*1000;
            comma++;
        }
        return ans;
    }
};