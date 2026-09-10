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
    int cnt = 0;

    private int[] dfs(TreeNode root, int sum, int nodecnt) {
        if (root == null)
            return new int[] { 0, 0 };
        int[] Left = dfs(root.left, sum, nodecnt);
        int[] Right = dfs(root.right, sum, nodecnt);

        sum = root.val + Left[0] + Right[0];
        nodecnt = 1 + Left[1] + Right[1];

        if (sum / nodecnt == root.val)
            cnt++;

        return new int[] { sum, nodecnt };

    }

    public int averageOfSubtree(TreeNode root) {
        dfs(root, 0, 0);
        return cnt;
    }
}