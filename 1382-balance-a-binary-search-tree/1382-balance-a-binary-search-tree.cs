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
    public TreeNode BalanceBST(TreeNode root) {
        var list = new List<TreeNode>();
        Inorder(root, list);

        return BalanceBST(list, 0, list.Count - 1);
    }
    TreeNode? BalanceBST(List<TreeNode> list, int st, int end) {
        if (st > end) {
            return null;
        }
        int mid = (st + end) / 2;
        var node = list[mid];
        node.left = BalanceBST(list, st, mid - 1);
        node.right = BalanceBST(list, mid + 1, end);
        return node;
    }
    void Inorder(TreeNode node, List<TreeNode> list) {
        if (node is null) {
            return;
        }

        Inorder(node.left, list);
        list.Add(node);
        Inorder(node.right, list);
    }
}