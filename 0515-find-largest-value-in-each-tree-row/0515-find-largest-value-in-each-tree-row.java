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
    public void dfs(int lvl, TreeNode root, List<Integer> res) {
        if (root == null)
            return;
        if (lvl == res.size())
            res.add(root.val);
        else
            res.set(lvl, Math.max(root.val, res.get(lvl)));
        dfs(lvl + 1, root.left, res);
        dfs(lvl + 1, root.right, res);
        return;
    }

    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        dfs(0, root, res);
        return res;
    }
}