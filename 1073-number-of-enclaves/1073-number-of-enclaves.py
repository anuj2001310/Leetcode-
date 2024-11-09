class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]

        n = len(grid)
        m = len(grid[0])
        vis = [[False for _ in range(m)] for _ in range(n)]

        def dfs(r, c):
            vis[r][c] = True
            for i in range(len(dirs)):
                nr = r + dirs[i][0]
                nc = c + dirs[i][1]
                if nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == 1 and not vis[nr][nc]:
                    dfs(nr, nc)
        

        for i in range(n):
            for j in range(m):
                if i == 0 or j == 0 or i == n - 1 or j == m - 1:
                    if grid[i][j] == 1 and not vis[i][j]:
                        dfs(i, j)
        
        return sum(1 for i in range(n) for j in range(m) if grid[i][j] == 1 and not vis[i][j])