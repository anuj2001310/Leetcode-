class Solution(object):
    def zigzagTraversal(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        n, m = len(grid), len(grid[0])
        res = []
        for i in range(n * m):
            if i % 2 == 1:
                continue
            x = i // m
            y = i % m
            if x % 2 == 1:
                y = m - y - 1
            res.append(grid[x][y])
        
        return res