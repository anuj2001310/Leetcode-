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
    public TreeNode ReverseOddLevels(TreeNode root) {
        void funct (TreeNode left, TreeNode right, int l) {
            if (left == null || right == null)
                return;
            
            if ((l & 1) != 0) {
                int t = left.val;
                left.val = right.val;
                right.val = t;
            }
            funct (left.left, right.right, l + 1);
            funct (left.right, right.left, l + 1);
            return ;
        }
        
        funct (root.left, root.right, 1);
        return root;
    }
}