# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        def dfs(lvl, node):
            if not node:
                return 

            if lvl == len(ans):
                ans.append(node.val)
            
            ans[lvl] = max(node.val, ans[lvl])

            dfs(lvl+1, node.left)
            dfs(lvl+1, node.right)

        dfs(0, root)

        return ans