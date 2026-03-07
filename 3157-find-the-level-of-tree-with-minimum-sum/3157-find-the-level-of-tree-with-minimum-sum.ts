/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function minimumLevel(root: TreeNode | null): number {
    const q: [TreeNode] = [root];
    let ans: number = 0, level: number = 1;
    let sum: number = Infinity;

    while (q.length > 0) {
        let n: number = q.length;
        let cur: number = 0;

        for (let i: number = 0; i < n; i++) {
            let node: TreeNode = q.shift();
            cur += node.val;

            if (node.left)
                q.push(node.left);
            if (node.right)
                q.push(node.right);
        }

        if (cur < sum) {
            sum = cur;
            ans = level;
        }
        level++;
    }

    return ans;
};