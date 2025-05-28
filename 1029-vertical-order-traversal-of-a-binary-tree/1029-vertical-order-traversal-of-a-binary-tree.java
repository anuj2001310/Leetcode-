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
    class Pair {
        int[] first;
        TreeNode second;

        Pair(int[] first, TreeNode second) {
            this.first = first;
            this.second = second;
        }
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null)
            return ans;

        Queue<Pair> q = new ArrayDeque<>();  //
        q.offer(new Pair(new int[] {0, 0}, root));

        Map<Integer, List<int[]>> map = new TreeMap<>();

        while (!q.isEmpty()) {
            int n = q.size();
            int dis = q.peek().first[0];
            int level = q.peek().first[1];
            TreeNode node = q.peek().second;
            q.poll();

            map.computeIfAbsent(dis, k -> new ArrayList<>()).add(new int[] {level, node.val});

            if (node.left != null)
                q.offer(new Pair(new int[] {dis - 1, level + 1}, node.left));
            if (node.right != null)
                q.offer(new Pair(new int[] {dis + 1, level + 1}, node.right));
        }

        for (Map.Entry<Integer, List<int[]>> em : map.entrySet()) {

            List<int[]> dummy = em.getValue();
            List<Integer> temp = new ArrayList<>();

            Collections.sort(dummy, (a, b) -> {
                if (a[0] == b[0])
                    return a[1] - b[1];
                return a[0] - b[0];
            });

            for (int[] ele : dummy)
                temp.add(ele[1]);

            ans.add(temp);
        }

        return ans;
    }
}