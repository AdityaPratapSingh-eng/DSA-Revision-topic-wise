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
        int solve(TreeNode* root){
              if(root==NULL)return 0;
 
              int l= solve(root->left);
              int h= solve(root->right);

              return 1+ max(l, h);
        }

    int maxDepth(TreeNode* root) {
         if(root==NULL)return 0;
         
        int l= solve(root->left);
        int h= solve(root->right);

        return  1+ max(l, h);
    }
};