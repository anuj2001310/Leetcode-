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
 * @param {number} k
 * @return {number}
 */
var kthLargestLevelSum = function (root, k) {
    let q = [root];
    let sums = [];
    while (q.length) {
        let newQ = [];
        let sum = 0;
        for (let i = 0; i < q.length; i++) {
            const node = q[i];
            sum = sum + node.val;
            if (node.left) newQ.push(node.left);
            if (node.right) newQ.push(node.right);
        }
        sums.push(sum);
        q = newQ;
    }

    sums.sort((a, b) => b - a);
    
    return sums[k - 1] || -1;
};