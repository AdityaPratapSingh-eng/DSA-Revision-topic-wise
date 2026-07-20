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

       void solve(TreeNode* root,  map<int, vector<pair<int, int>>>&mp, int col, int row){
             if(root==NULL){
                 
                 return ;
             }
            
            mp[col].push_back({row, root->val});
             
             
         
            solve(root->left, mp, col-1, row+1);
            solve(root->right, mp, col+1, row+1);
       }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
            map<int, vector<pair<int, int>>>mp;
         
          solve(root, mp, 0, 0);
          vector<vector<int>>ans;
          
          for(auto & a: mp){
              vector<int>temp;
              vector<pair<int,int>>&row_col= a.second;
              sort(row_col.begin(), row_col.end());
            for(int i=0; i<row_col.size(); i++){
                temp.push_back(row_col[i].second);
            }
            
            ans.push_back(temp);
          }
          return ans;
    }
};