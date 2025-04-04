/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var lcaDeepestLeaves = function(root) {
    const dfs = (root) => {
        if (!root)
            return [null, 0]
        
        let left = dfs(root.left);
        let right = dfs(root.right);
        
        if (left[1] > right[1])
            return [left[0], left[1] + 1]
        if (left[1] < right[1])
            return [right[0], right[1] + 1]
        
        return [root, left[1] + 1]
    }
    return dfs(root)[0];
};