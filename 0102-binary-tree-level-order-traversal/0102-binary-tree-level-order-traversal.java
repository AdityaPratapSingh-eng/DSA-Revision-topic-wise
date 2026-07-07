/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    void bfs(TreeNode root,  List<List<Integer>> ans){
        if(root==null)return ;

        Queue<TreeNode>q= new LinkedList<TreeNode>();
    
        q.offer(root);
          int level =0;

        while(!q.isEmpty()){
            int n= q.size();
             ans.add(new ArrayList<>());
           
             for(int i=0; i<n; i++){
            TreeNode curr = q.poll();
             ans.get(level).add(curr.val);

             if(curr.left!= null){
                q.offer(curr.left);
             }

             if(curr.right!= null){
                q.offer(curr.right);
             }
                  
             }
              level++;
        }
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
      List<List<Integer>> ans = new ArrayList<>();

         bfs(root, ans);

         return ans;
    }
}