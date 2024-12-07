class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        n = len(grid)
        m = len(grid[0])
        maxArea = 0
        vis = [[False for _ in range(m)] for _ in range(n)]

        def bfs (r, c):
            cnt = 0
            q = deque()
            vis[r][c] = True
            q.append([r, c])

            while q:
                R, C = q.popleft()
                cnt += 1
                for i in range(len(dirs)):
                    nR = R + dirs[i][0]
                    nC = C + dirs[i][1]
                    if 0 <= nR < n and 0 <= nC < m and grid[nR][nC] == 1 and not vis[nR][nC]:
                        q.append([nR, nC])
                        vis[nR][nC] = True
            del q
            return cnt
        

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and not vis[i][j]:
                    maxArea = max(maxArea, bfs(i, j))
                    
        del vis
        del grid
        del dirs
        return maxArea