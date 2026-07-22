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

  void  solve(TreeNode*root, string temp, vector<string>&ans){
             if(root==NULL)return ;
             temp+=to_string(root->val);

           if(root->left==NULL && root->right==NULL){
              ans.push_back(temp);
              return ;
           }
             temp+= "->";
            
         solve(root->left, temp, ans);
         solve(root->right, temp, ans);
          
  }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
           if(root->left== NULL  && root->right==NULL){
            ans.push_back(to_string(root->val));
            return ans;
           }
             string temp="";
           solve(root,  temp, ans);

           return  ans;
    }
};