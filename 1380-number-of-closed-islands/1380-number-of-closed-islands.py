class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        n, m = len(grid), len(grid[0])
        vis = [[False for _ in range(m)] for _ in range(n)]
        print(vis)
        def dfs (r, c):
            vis[r][c] = True
            for i in range(len(dirs)):
                nr = r + dirs[i][0]
                nc = c + dirs[i][1]
                if 0 <= nr < n and 0 <= nc < m and not vis[nr][nc] and grid[nr][nc] == 0:
                    dfs(nr, nc)
            
        
        for i in range(n):
            for j in range(m):
                if i == 0 or i == n - 1 or j == 0 or j == m - 1:
                    if grid[i][j] == 0 and not vis[i][j]:
                        dfs(i, j)
        
        cnt = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0 and not vis[i][j]:
                    cnt += 1
                    dfs(i, j)
        return cnt
