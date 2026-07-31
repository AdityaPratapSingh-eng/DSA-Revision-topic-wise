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

        int lheight(TreeNode*l){
                if(l==NULL){
                    return 0;
                }
                return  1+ lheight(l->left);
        }

        int rheight(TreeNode*r){
                if(r==NULL){
                    return 0;
                }
                return  1+ rheight(r->right);
        }
    int countNodes(TreeNode* root) {

          if(root==NULL)return 0;

          if(root->left==NULL && root->right== NULL)return 1;
        int l= lheight(root);
        int r= rheight(root);
        if(l==r){
            return (1<<l)-1;
        }

        return 1+ countNodes(root->left)+ countNodes(root->right);
    }
};