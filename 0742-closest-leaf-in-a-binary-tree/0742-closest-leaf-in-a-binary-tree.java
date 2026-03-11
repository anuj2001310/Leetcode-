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
    int minDistance = 1001;
    int nodeVal = 0;

    public int findClosestLeaf(TreeNode root, int k) {
        Map<TreeNode, Integer> map = new HashMap<>();
        buildMap(root, map, k);
        dfsHelper(root, map, 0, k);
        //System.out.println(map);
        return nodeVal;
    }

    public int buildMap(TreeNode root, Map<TreeNode, Integer> map, int k) {
        if (root == null)
            return -1;
        
        if (root.val == k) {
            map.put(root, 0);
            return 0;
        }
        int left = buildMap(root.left, map, k);
        int right = buildMap(root.right, map, k);
        if (left >= 0) {
            map.put(root, left + 1);
            return left + 1;
        }
        if (right >= 0) {
            map.put(root, right + 1);
            return right + 1;
        }
        return -1;
    }

    public void dfsHelper(TreeNode root, Map<TreeNode, Integer> map, int distance, int k) {
        if (root == null) {
            return;
        }
        if (map.containsKey(root)) {
            distance = map.get(root);
        }
        if (root.left == null && root.right == null && distance < minDistance) {
            //System.out.println(minDistance);
            //System.out.println(distance);
            minDistance = distance;
            nodeVal = root.val;
            return;
        }

        dfsHelper(root.left, map, distance + 1, k);
        dfsHelper(root.right, map, distance + 1, k);
    }
}