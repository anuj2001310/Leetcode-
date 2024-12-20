/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    private void function(TreeNode left, TreeNode right, int level) {
        if (left == null || right == null)
            return;
        if ((level & 1) != 0) {
            int tmp = left.val;
            left.val = right.val;
            right.val = tmp;
        }
        function(left.left, right.right, level + 1);
        function(left.right, right.left, level + 1);
        return;
    }

    public TreeNode reverseOddLevels(TreeNode root) {
        function(root.left, root.right, 1);
        return root;
    }
}