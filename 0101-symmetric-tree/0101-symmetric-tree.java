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
    boolean dfs(TreeNode l, TreeNode r) {
        if (l == null && r != null)
            return false;
        if (l != null && r == null)
            return false;
        if (l == null && r == null)
            return true;
        boolean value = (l.val == r.val);
        boolean left = dfs(l.left, r.right);
        boolean right = dfs(l.right, r.left);
        return (left && right && value);
    }

    public boolean isSymmetric(TreeNode root) {
        return dfs(root.left, root.right);
    }
}