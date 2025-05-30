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
    public IList<IList<int>> PathSum(TreeNode root, int targetSum) {
        var ans = new List<IList<int>>();
        var path = new List<int>();

        void func(TreeNode root, int sum, int target) {
            if (root == null)
                return ;
            
            path.Add(root.val);
            sum += root.val;

            if (root.left == null && root.right == null && sum == target)
                ans.Add(new List<int>(path));
            func(root.left, sum, target);
            func(root.right, sum, target);
            path.RemoveAt(path.Count - 1);
        }
        
        func(root, 0, targetSum);
        return ans;
    }
}