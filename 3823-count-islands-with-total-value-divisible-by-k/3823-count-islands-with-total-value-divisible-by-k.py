class Solution(object):
    def countIslands(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        n, m = len(grid), len(grid[0])
        vis = [[False for _ in range(m)] for _ in range(n)]
        ct = 0

        def dfs (r, c):
            if r >= n or r < 0 or c >= m or c < 0 or vis[r][c] or grid[r][c] == 0:
                return 0
            vis[r][c] = True
            s = grid[r][c]

            s += dfs (r - 1, c)
            s += dfs (r, c + 1)
            s += dfs (r + 1, c)
            s += dfs (r, c - 1)
            return s
            
        for i in range(n):
            for j in range(m):
                if not vis[i][j] and grid[i][j]:
                    val = dfs (i, j)
                    if val % k == 0:
                        ct += 1
        
        return ct