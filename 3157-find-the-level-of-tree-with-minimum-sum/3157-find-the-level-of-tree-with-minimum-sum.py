# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumLevel(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        ans, l = 0, 1
        S = inf

        while q:
            n = len(q)
            curr = 0

            for _ in range(n):
                node = q.popleft()
                curr += node.val

                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            if curr < S:
                S = curr
                ans = l
            l += 1
        
        return ans