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
    private void func(TreeNode root, List<List<Integer>> ans, List<Integer> path, int sum, int target) {
        if (root == null)
            return;
        sum += root.val;
        path.add(root.val);
        if (root.left == null && root.right == null && sum == target)
            ans.add(new ArrayList<>(path));

        func(root.left, ans, path, sum, target);
        func(root.right, ans, path, sum, target);
        path.remove(path.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null)
            return ans;
        func(root, ans, new ArrayList<Integer>(), 0, targetSum);
        return ans;
    }
}