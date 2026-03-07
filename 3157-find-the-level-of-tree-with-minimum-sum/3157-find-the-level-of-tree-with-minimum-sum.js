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
 * @return {number}
 */
var minimumLevel = function (root) {
    let q = [root];
    let ans = 0;
    let level = 1;
    let minSum = Infinity;

    while (q.length > 0) {
        let n = q.length;
        let curr = 0;

        for (let i = 0; i < n; i++) {
            let node = q.shift();
            curr += node.val;

            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }

        if (curr < minSum) {
            minSum = curr;
            ans = level;
        }

        level++;
    }

    return ans;
};