/**
 * Definition for Node.
 * public class Node {
 *     int val;
 *     Node left;
 *     Node right;
 *     Node random;
 *     Node() {}
 *     Node(int val) { this.val = val; }
 *     Node(int val, Node left, Node right, Node random) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *         this.random = random;
 *     }
 * }
 */

class Solution {
    public NodeCopy copyRandomBinaryTree(Node root) {
        Map<Node, NodeCopy> map = new HashMap<>();
        return doClone(root, map);
    }

    private NodeCopy doClone(Node root, Map<Node, NodeCopy> map) {
        if (root == null) {
            return null;
        }
        if (map.containsKey(root)) {
            return map.get(root);
        } else {
            NodeCopy cur = new NodeCopy(root.val);
            map.put(root, cur);
            cur.left = doClone(root.left, map);
            cur.right = doClone(root.right, map);
            cur.random = doClone(root.random, map);
            return cur;
        }
    }
}