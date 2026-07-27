/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

      unordered_map<TreeNode*, TreeNode*>parent;

      void connect(TreeNode*root){
          if(root==NULL)return ;

          if(root->left){
            parent[root->left]= root;
          }
          connect(root->left);

          if(root->right){
            parent[root->right]= root;
          }
          connect(root->right);
      }
           
         void bfs(TreeNode*target , vector<int>&result, int k){
                unordered_set<int>vis;

                queue<TreeNode*>q;
                q.push(target);
                vis.insert(target->val);
                while(!q.empty()){
                    int n= q.size();

                    if(k==0){
                        break;
                    }
                    while(n--){
                        TreeNode*curr= q.front();
                         q.pop();
                        if(curr->left && !vis.count(curr->left->val)){
                            q.push(curr->left);
                            vis.insert(curr->left->val);
                        }

                         if(curr->right && !vis.count(curr->right->val)){
                            q.push(curr->right);
                            vis.insert(curr->right->val);
                        }

                        if(parent[curr] &&  !vis.count(parent[curr]->val)){
                            q.push(parent[curr]);
                            vis.insert(parent[curr]->val);
                        }
                    }
                    k--;
                }

                while(!q.empty()){
                    result.push_back(q.front()->val);

                    q.pop();
                }


         }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;
       connect(root);
        bfs(target, result,k );

        return result;
    }
};