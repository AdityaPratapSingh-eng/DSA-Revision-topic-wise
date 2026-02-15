#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int>g(n);    // greedy factor of children
    vector<int>s(m);  // size of cookies
    cout<<" enter the children greedy factor ";  
    for(int i=0; i<n; i++){    
        cin>>g[i];
    }
    cout<<" enter the size of cookies ";
    for(int i=0; i<m; i++){
        cin>>s[i];
    }
    int count=0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i=0,  j=0;
    while(i<n && j<m){
      if(g[i]<= s[j]){
        count++;
        i++;
        j++;
      }
    }
    cout<<"children with  max no. of cookies is = "<<count;
        

}
