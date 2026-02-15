#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>nums(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin>>nums[i][0]>>nums[i][1];
    }
    sort(nums.begin(), nums.end(), [](vector<int>&a, vector<int>&b){
        return a[1]< b[1];}
    );
    

    int aerrow=1;
     int xend= nums[0][1];
    for(int i=0; i<n; i++){
        int curr= nums[i][0];
        if(xend>= curr){
            continue;
        }
        else{
            aerrow++;
            xend= nums[i][1];
        }

    }
    cout<<aerrow<<endl;
}