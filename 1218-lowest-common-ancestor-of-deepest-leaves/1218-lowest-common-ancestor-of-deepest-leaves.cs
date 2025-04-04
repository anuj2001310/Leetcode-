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
class Pair {
    public TreeNode root;
    public int depth;
    public Pair (TreeNode root, int depth) {
        this.root = root;
        this.depth = depth;
    }
}

public class Solution {
    private Pair dfs (TreeNode root) {
        if (root == null)
            return new Pair(null, 0);
        
        Pair left = dfs (root.left);
        Pair right = dfs (root.right);
        
        if (left.depth > right.depth)
            return new Pair(left.root, left.depth + 1);
        
        if (left.depth < right.depth)
            return new Pair(right.root, right.depth + 1);
        
        return new Pair(root, left.depth + 1);    
    }
    
    public TreeNode LcaDeepestLeaves(TreeNode root) {
        return dfs(root).root;
    }
}