/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int MinimumLevel(TreeNode root) {
        var l = 1;
        var ans = 0;
        long sum = Int64.MaxValue;

        var q = new Queue<TreeNode>();
        q.Enqueue(root);
        

        while (q.Count > 0) {
            int n = q.Count;
            long curr = 0;

            for (var i = 0; i < n; i++) {
                TreeNode node = q.Dequeue();
                curr += node.val;

                if (node.left != null)
                    q.Enqueue(node.left);
                if (node.right != null)
                    q.Enqueue(node.right);
            }

            if (curr < sum) {
                sum = curr;
                ans = l;
            }
            
            l++;
        }
        return ans;
    }
}