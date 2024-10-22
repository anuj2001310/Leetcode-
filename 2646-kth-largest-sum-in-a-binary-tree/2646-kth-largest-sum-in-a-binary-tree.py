# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        res = []
        q = deque([root])
        while q:
            sm = 0
            n = len(q)
            for _ in range(n):
                node = q.popleft()
                sm += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res.append(sm)

        if k > len(res):
            return -1

        res.sort()
        k -= 1

        while k:
            k -= 1
            res.pop()
            
        return res.pop()
