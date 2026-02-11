# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
    
        m = defaultdict(list)
        q = deque([(root, 0)]) 

        while q:
            node, dis = q.popleft()
            m[dis].append(node.val)

            if node.left:
                q.append((node.left, dis - 1))
            if node.right:
                q.append((node.right, dis + 1))

        return [m[x] for x in sorted(m)]
                
