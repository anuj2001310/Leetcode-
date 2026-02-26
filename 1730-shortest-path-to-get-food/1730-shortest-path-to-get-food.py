class Solution:
    def getFood(self, grid: List[List[str]]) -> int:

        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        
        n, m = len(grid), len(grid[0])
        vis = [[False for _ in range(m)] for _ in range(n)]

        q = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '*':
                    vis[i][j]  = True
                    q.append([0, i, j])
        
        while q:
            t, r, c = q.popleft()
            if grid[r][c] == '#':
                return t
            
            for d in dirs:
                nr = r + d[0]
                nc = c + d[1]

                if 0 <= nr < n and 0 <= nc < m and not vis[nr][nc] and grid[nr][nc] != 'X':
                    vis[nr][nc] = True
                    q.append([t + 1, nr, nc])
            
        return -1
