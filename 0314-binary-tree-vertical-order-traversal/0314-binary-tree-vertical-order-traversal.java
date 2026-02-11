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
    class pair {
        TreeNode node;
        int dis;
        pair(TreeNode node, int dis) {
            this.node = node;
            this.dis = dis;
        }
    }

    public List<List<Integer>> verticalOrder(TreeNode root) {
        if (root == null)
            return new ArrayList<>();
        
        Map<Integer, List<Integer>> map = new TreeMap<>();
        Queue<pair> q = new ArrayDeque<>();

        q.offer(new pair(root, 0));
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode node = q.peek().node;
                int dis = q.peek().dis;
                q.poll();

                map.computeIfAbsent(dis, k -> new ArrayList<>()).add(node.val);

                if (node.left != null)
                    q.offer (new pair(node.left, dis - 1));

                if (node.right != null)
                    q.offer (new pair(node.right, dis + 1));
                }
        }

        List<List<Integer>> ans = new ArrayList<>();
        for (Map.Entry<Integer, List<Integer>> em : map.entrySet())
            ans.add(em.getValue());
        
        return ans;
    }
}