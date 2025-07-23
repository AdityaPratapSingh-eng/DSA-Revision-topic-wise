# Advance-Dsa-

class Solution {
public:
    int maximumGain(string s, int x, int y) {
         stack<char>st;
         int TotalScore=0;
         string first="ab";
         string second= "ba";
         int firstScore=x;
         int secondScore= y;
         if(x<y){
            swap(first, second);
            swap(firstScore, secondScore);
         }
       for(char i : s){
       if(!st.empty() && st.top()==first[0]&& i==first[1]){

        st.pop();
        TotalScore+= firstScore;
       }
 else{
       st.push(i);


 }
       }
       string temp;
       while(!st.empty()){
          temp+= st.top();
              st.pop();
       }
       reverse(temp.begin(), temp.end());
          for(char i : temp){
       if(!st.empty() && st.top()==second[0]&& i==second[1]){

        st.pop();
        TotalScore+= secondScore;
       }
 else{
       st.push(i);


 }
       }
       




     return TotalScore;
    }
};
