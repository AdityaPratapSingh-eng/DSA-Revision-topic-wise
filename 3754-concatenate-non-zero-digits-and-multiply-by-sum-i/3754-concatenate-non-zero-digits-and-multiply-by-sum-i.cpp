class Solution {
public:
    long long sumAndMultiply(int n) {
        string s= to_string(n);
        string ans="";
        long long sum=0;
        if(n==0){
            return 0;
        }
        for(char a: s){
            if(a!='0'){
                ans+=a;
                sum+=a-'0';
            }
        }
        return  (long long)stoi(ans)*sum;
    }
};