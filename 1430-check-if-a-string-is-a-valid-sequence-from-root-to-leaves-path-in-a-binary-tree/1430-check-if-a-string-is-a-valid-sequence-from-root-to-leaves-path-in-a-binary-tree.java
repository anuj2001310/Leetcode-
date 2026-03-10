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
    private boolean helper(int idx, int n, TreeNode root, int[] arr) {
        if (root == null || root.val != arr[idx])
            return false;
        
        if (idx == n - 1)
            return root.left == null && root.right == null;
        
        if (arr[idx] != root.val)
            return false;
        
        return helper(idx + 1, n, root.left, arr) || helper(idx + 1, n, root.right, arr);
    }
    
    public boolean isValidSequence(TreeNode root, int[] arr) {
        int n = arr.length;
        return helper(0, n, root, arr);
    }
}