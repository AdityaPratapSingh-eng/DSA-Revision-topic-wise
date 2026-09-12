class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n= digits.size();
     unordered_set<int>st;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
               for(int k=j+1; k<n; k++){
                      
                    int num1= digits[i]*100+ digits[j]*10+ digits[k];
                    int num2= digits[i]*100+ digits[k]*10+ digits[j];
                    int num3= digits[j]*100+ digits[i]*10+ digits[k];
                    int num4= digits[j]*100+ digits[k]*10+ digits[i];
                    int num5= digits[k]*100+ digits[i]*10+ digits[j];
                    int num6= digits[k]*100+ digits[j]*10+ digits[i];

                    if(digits[i]!= 0 && num1%2==0){
                        st.insert(num1);
                    }
                    if(digits[i]!= 0 && num2%2==0){
                        st.insert(num2);
                    }
                    if(digits[j]!= 0  && num3%2==0){
                        st.insert(num3);
                    }

                    if(digits[j]!= 0 && num4%2==0){
                        st.insert(num4);
                    }
                    if(digits[k]!= 0 && num5%2==0){
                        st.insert(num5);
                    }
                    if(digits[k]!= 0 && num6%2==0){
                        st.insert(num6);
                    }
                    
               }
            }
           }
            
           return st.size();
    }
};