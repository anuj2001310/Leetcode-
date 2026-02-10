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
    double min = Integer.MAX_VALUE;
    int result = Integer.MAX_VALUE;

    public int closestValue(TreeNode root, double target) {
        if (root == null)
            return result;
        int val = root.val;
        double diff = Math.abs(target - (double) val);
        if (diff < min) {
            min = diff;
            result = val;
        } else if (diff == min) {
            min = diff;
            result = Math.min(result, val);
        }
        closestValue(root.left, target);
        closestValue(root.right, target);
        return result;
    }
}