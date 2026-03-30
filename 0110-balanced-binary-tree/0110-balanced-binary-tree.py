# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def balanced(node: node):
            if not node:
                return True, 0

            balanced_l, height_l = balanced(node.left)
            balanced_r, height_r = balanced(node.right)
            balance = balanced_l and balanced_r and abs(height_r - height_l) <= 1
            height = 1 + max(height_l, height_r)

            return balance, height

        if not root:
            return True

        val, _ = balanced(root)
        return val
