/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

     void solve(TreeNode*root, map<int, int>&mp, int row){
         
          queue<pair<TreeNode*, int>>q;
          
          q.push({root, row});
          
          while(!q.empty()){
              TreeNode*curr= q.front().first;
              int r= q.front().second;
              
              q.pop();
              
            
                  mp[r]=  curr->val;
              
              
              if(curr->left){
                  q.push({curr->left, r+1});
              }
              if(curr->right){
                  q.push({curr->right, r+1});
              }
          }
         
         
         
     }

    vector<int> rightSideView(TreeNode* root) {
             
              
      map<int, int>mp;
        vector<int>ans;
         if(root==NULL)return ans;
        solve(root, mp, 0);
        
        for(auto &a: mp){
            ans.push_back(a.second);
        }
        return ans;
    }
};