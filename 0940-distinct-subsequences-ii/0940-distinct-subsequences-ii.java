class Solution {
    public int distinctSubseqII(String s) {
        int []t= new int [26];
        int M = 1_000_000_007; 
       
        int total=0;
        

        for(int i=0; i<s.length(); i++){
                  
             int idx= s.charAt(i)- 'a';

          int   newSub= (total+ 1- t[idx]+M) %M;

               total= (total+ newSub)%M;
              t[idx]= (t[idx] + newSub)%M;
             
        }
        return total;
    }
}