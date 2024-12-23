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
    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int swaps = 0;

        while (!q.isEmpty()) {
            int n = q.size();
            ArrayList<Integer> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode node = q.poll();
                arr.add(node.val);

                if (node.left != null)
                    q.add(node.left);
                if (node.right != null)
                    q.add(node.right);
            }

            swaps += function(arr);
        }
        return swaps;
    }

    private int function(ArrayList<Integer> arr) {
        int swaps = 0;
        ArrayList<Integer> temp = new ArrayList<>(arr);
        Collections.sort(temp);

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.size(); i++)
            map.put(arr.get(i), i);

        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i) != temp.get(i)) {
                swaps++;

                int curPos = map.get(temp.get(i));
                map.put(arr.get(i), curPos);
                arr.set(curPos, arr.get(i));
            }
        }
        return swaps;
    }
}