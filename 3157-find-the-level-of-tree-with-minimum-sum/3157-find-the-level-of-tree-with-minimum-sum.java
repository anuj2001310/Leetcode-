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
    public int minimumLevel(TreeNode root) {
        int ans = 0;
        long sum = Long.MAX_VALUE;
        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int l = 1;

        while (!q.isEmpty()) {
            int n = q.size();
            long curr = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode node = q.poll();
                curr += node.val;

                if (node.left != null)
                    q.offer(node.left);
                
                if (node.right != null)
                    q.offer(node.right);
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