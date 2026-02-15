#include<bits/stdc++.h>
using namespace std;
 int main(){
    int k, w;
     int p, c;
     cin>>p,c;
    cin>>k>>w;
    vector<int>profits(p);
    vector<int>capital(c);
    

    cout<<" enter the profits of projects ";
    for(int i=0; i<p; i++){
        cin>>profits[i];
    }
    cout<<" enter the capital of projects ";
    for(int i=0; i<c; i++){
        cin>>capital[i];
    }
    vector<pair<int, int>>projects;
    for(int i=0; i<p; i++){
        projects.push_back({capital[i], profits[i]});
    }
      sort(projects.begin(), projects.end());
        int i=0;
    priority_queue<int>pq;
    while(k--){
             while(i<p && projects[i].first<=w){
                pq.push(projects[i].second);
                i++;
             }
                if(pq.empty()){
                    break;
                }
                w+=pq.top();
                pq.pop();

    }
         cout<<" maximum capital after completing at most k projects is = "<<w;

 }