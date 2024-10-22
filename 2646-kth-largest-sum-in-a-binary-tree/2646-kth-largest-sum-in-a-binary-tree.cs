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
    public long KthLargestLevelSum(TreeNode root, int k) {
        PriorityQueue<long, long> pq = new();
        Queue<TreeNode> queue = [];
        queue.Enqueue(root);

        while(queue.Count > 0)
        {
            int levelSize = queue.Count;
            long sum = 0;

            for(int i = 0; i < levelSize; i++)
            {
                var node = queue.Dequeue();

                sum += node.val;

                if(node.left!=null)
                    queue.Enqueue(node.left);
                if(node.right!=null)
                    queue.Enqueue(node.right);
            }
            pq.Enqueue(sum, -sum); // Negative priority for descending sorting
        }    

        // Number of levels lesser than k
        if(k > pq.Count)
            return -1;

        // Pop k-1 times to reach the kth sum
        while(k > 1){
            pq.Dequeue();
            k--;
        }

        return pq.Peek();
    }
}