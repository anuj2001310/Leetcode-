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
    private int funct(List<int> arr) {
        if (arr.Count() == 1)
            return 0;

        int n = 0;
        List<int> temp = new List<int>(arr);
        temp.Sort();
        var map = new Dictionary<int, int>();
        for (int i = 0; i < arr.Count(); i++)
            map.Add(arr[i], i);

        for (int i = 0; i < arr.Count(); i++) {
            if (arr[i] != temp[i]) {
                n++;

                int c = map[temp[i]];
                map[arr[i]] =  c;
                arr[c] = arr[i];
            }
        }

        return n;

    }
    public int MinimumOperations(TreeNode root) {
        var q = new Queue<TreeNode>();
        int s = 0;
        q.Enqueue(root);
        while (q.Count() != 0) {
            int n = q.Count();
            var arr = new List<int>();
            for (var i = 0; i < n; i++) {
                TreeNode node = q.Dequeue();
                arr.Add(node.val);
                if (node.left != null)
                    q.Enqueue(node.left);
                if (node.right != null)
                    q.Enqueue(node.right);
            }
            s += funct(arr);
        }
        return s;
    }
}