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
 

      int bfs(TreeNode*root){
        queue<pair<TreeNode*, long long >>q;

        q.push({root, 0});
       long long   width=0;
        while(!q.empty()){
            long long  st= q.front().second;
            long long  ed= q.back(). second;
            width= max(width, ed- st+1 );

            int n= q.size();

            for(int i=0; i<n; i++){

                  TreeNode*curr= q.front().first;
                     int idx= q.front().second;
                    q.pop();

                    if(curr->left){
                        q.push({curr->left, (long long)2*idx+1});
                    }
                      if(curr->right){
                        q.push({curr->right, (long long)2*idx+2});
                    }
            }
        }
        return width;
      }
    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);
    }
};