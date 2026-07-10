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
     int maxSum;
   int solve(TreeNode*root){
       if(root==NULL)return 0;

       int l= solve(root->left);
       int r= solve(root->right);

       //neeche hi sum mil gaya
   int downSum= l+r+ root->val;

    // only one path sum

    int l_or_r= max(l, r)+ root->val;

    // only root

    int only_root= root->val;


    maxSum=  max({maxSum, downSum, l_or_r, only_root});


    return max(l_or_r, only_root);

       
   }
    int maxPathSum(TreeNode* root) {
          maxSum= INT_MIN;
        solve(root);
   
        return maxSum;

    }
};