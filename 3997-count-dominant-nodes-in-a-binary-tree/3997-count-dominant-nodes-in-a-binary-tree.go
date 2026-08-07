/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func countDominantNodes(root *TreeNode) int {
	cnt := 0

	max := func(x, y int) int {
		if x < y {
			return y
		}
		return x
	}

	var postOrder func(*TreeNode) int
    
	postOrder = func(root *TreeNode) int {
		if root == nil {
			return math.MinInt
		}

		left := postOrder(root.Left)
		right := postOrder(root.Right)

		m := max(root.Val, max(left, right))

		if m == root.Val {
			cnt++
		}
		return m
	}

	postOrder(root)
	return cnt
}