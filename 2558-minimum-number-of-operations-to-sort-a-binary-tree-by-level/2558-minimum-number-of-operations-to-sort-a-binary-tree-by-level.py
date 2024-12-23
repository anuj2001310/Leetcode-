# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minimumOperations(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        q = deque([root])
        swap = 0
        def function(res):
            n = 0
            t = [x for x in res]
            t.sort()
            maps = {}
            for i in range(len(res)):
                maps[res[i]] = i
            
            for i in range(len(res)):
                if res[i] != t[i]:
                    n += 1
                    curr = maps[t[i]]
                    maps[res[i]] = curr
                    res[curr] = res[i]
            return n

        while q:
            n = len(q)
            res = []
            for i in range(n):
                node = q.popleft()
                res.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            
            swap += function (res)
        
        return swap