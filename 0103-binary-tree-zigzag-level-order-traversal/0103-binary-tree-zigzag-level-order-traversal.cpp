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

       
          void bfs(TreeNode* root, vector<vector<int>>&ans){
               queue<TreeNode*>q;
                 bool rev= false;
              
               ans.push_back({root->val});
                 rev= true;
               q.push(root);
  
               while(!q.empty()){
                    int n= q.size();
                     vector<int>l;
                    for(int i=0; i<n; i++){
                         TreeNode* curr=  q.front();
                    q.pop();
                     if(curr->left){
                        l.push_back(curr->left->val);
                        q.push(curr->left);
                     }
                     if(curr->right){
                          l.push_back(curr->right->val);
                        q.push(curr->right);
                     }
                    }

                    if( rev && l.size()>0){
                        reverse(l.begin(), l.end());
                        
                        rev= false;
                    }

                     else{
                        rev= true;
                     }
                     if(l.size()>0){
                        ans.push_back(l);
                    }
                    
                      
               }

          }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
         if(root==NULL)return ans;
       bfs(root, ans);


       return ans;
    }
};