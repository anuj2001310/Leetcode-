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
var minimumOperations = function (root) {
    let res = 0
    let queue = [root]
    //  console.log(queue)
    while (queue.length) {
        const newQueue = []
        const arr = []
        let pos = []
        const posNum = {}
        const numPos = {}
        for (let i = 0; i < queue.length; i++) {
            q = queue[i]
     
            arr.push([q.val, i])
            pos.push(q.val)
            posNum[i] = q.val
            numPos[q.val] = i
            if (q.left) {
                newQueue.push(q.left)
            }
            if (q.right) {
                newQueue.push(q.right)
            }
        }
        pos.sort((a, b) => a - b)

        for (let i = 0; i < pos.length; i++) {
            if (posNum[i] === pos[i]) continue
            res++
            const numOnCurrPos = posNum[i]
            const moveNumOnPos = numPos[pos[i]]
            numPos[pos[i]] = i
            posNum[i] = pos[i]
            numPos[numOnCurrPos] = moveNumOnPos
            posNum[moveNumOnPos] = numOnCurrPos

        }
        queue = newQueue
    }
    return res
};