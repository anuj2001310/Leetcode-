/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
  func dfs(left *TreeNode, right *TreeNode, l int) {
        if left == nil || right == nil {
            return
        }
        if l & 1 != 0 {
            t := left.Val
            left.Val = right.Val
            right.Val = t
        }
        dfs (left.Left, right.Right, l + 1)
        dfs (left.Right, right.Left, l + 1)
        return
    }
func reverseOddLevels(root *TreeNode) *TreeNode {
   

    dfs(root.Left, root.Right, 1)
    return root 
}