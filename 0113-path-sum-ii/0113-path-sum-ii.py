# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: List[List[int]]
        """
        ans = []
        path = []

        def func(root, sm, target):
            if not root:
                return
            path.append(root.val)
            sm += root.val
            if not root.left and not root.right and sm == target:
                ans.append([x for x in path])
            
            func(root.left, sm, target)
            func(root.right, sm, target)
            path.pop()
        func(root, 0, targetSum)
        return ans