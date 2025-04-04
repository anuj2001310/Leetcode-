# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def lcaDeepestLeaves(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        def dfs (root):
            if not root:
                return [None, 0]
        
            left = dfs (root.left)
            right = dfs (root.right)

            if left[1] > right[1]:
                return [left[0], left[1] + 1]
        
            if left[1] < right[1]:
                return [right[0], right[1] + 1]
                
            return [root, left[1] + 1]
    
        return dfs(root)[0]