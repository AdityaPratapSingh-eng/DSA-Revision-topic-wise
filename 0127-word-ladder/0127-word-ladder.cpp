class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            queue<pair<string, int>>q;
            set<string>pool(wordList.begin(), wordList.end());
           
            q.push({beginWord, 1}); 
            pool.erase(beginWord);
            while(!q.empty()){
                string curr= q.front().first;
                int level= q.front().second;
                q.pop();
                  if(curr==endWord)return level;
                 
                 for(int i=0; i<curr.size(); i++){
                         char org = curr[i];
                       for(char ch= 'a'; ch<='z'; ch++){
                             curr[i]= ch;
                          if(pool.find(curr)!= pool.end()){
                           q.push({curr, level+1});
                           pool.erase(curr);
                       }
                     
                           curr[i]= org;
                       }
                       
                 }
                
            
            }

                  
                return 0;    
             }
};