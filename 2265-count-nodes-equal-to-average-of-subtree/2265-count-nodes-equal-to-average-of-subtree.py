# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        ans = 0
        def helper(node, sun, height):
            nonlocal ans
            if not node:
                return (0, 0)
            
            Left = helper(node.left , sun, height)
            Right = helper(node.right, sun, height)
            
            sun = Left[0] + Right[0] + node.val
            height = 1 + Left[1] + Right[1]
            
            if sun // height == node.val:
                ans += 1
            return (sun, height)
        
        helper(root, 0, 0)
        return ans