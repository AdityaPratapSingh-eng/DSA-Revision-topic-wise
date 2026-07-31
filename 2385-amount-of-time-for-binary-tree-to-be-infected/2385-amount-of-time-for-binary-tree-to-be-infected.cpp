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
   unordered_map<TreeNode*, TreeNode*>mp;
      void connect(TreeNode*root){
          if(root==NULL)return;

             if(root->left){
             mp[root->left]= root;
             }

               connect(root->left);
             if(root->right){
             mp[root->right]= root;
             }
               connect(root->right);
             
      }

           TreeNode*find_infected(TreeNode*root,  int start){
                 if(root==NULL){
                    return NULL;
                 }
                if(root->val== start){
                    return root;
                }

              TreeNode*l= find_infected(root->left, start);

              if(l!=NULL)
                 return l;

                  return find_infected(root->right, start);
           }
       int bfs(TreeNode*root,  unordered_set<int>&vis, TreeNode*inf)
       {
              queue<TreeNode*>q;
                int ans=-1;
              q.push(inf);

              vis.insert(inf->val);
              while(!q.empty()){
                  int n= q.size();

                  while(n--){
                      TreeNode*curr= q.front();
                      q.pop();
                   // left child
                      if( curr->left && !vis.count(curr->left->val)){
                        q.push(curr->left);
                           vis.insert(curr->left->val);
                      }
                    //right child
                      if( curr->right && !vis.count(curr->right->val)){
                        q.push(curr->right);
                           vis.insert(curr->right->val);
                      }
                  if(mp[curr] && !vis.count(mp[curr]->val)){
                       q.push(mp[curr]);
                       vis.insert(mp[curr]->val);
                  }


                  }
                  ans++;
              }
            return ans;
       }
    int amountOfTime(TreeNode* root, int start) {
        connect(root);

        unordered_set<int>vis;


        TreeNode*inf=  find_infected(root, start);
        return bfs(root, vis, inf);

    }
};