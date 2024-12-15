class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        time = -1
        n = len(grid)
        m = len(grid[0])
        vis = [[False for _ in range(m)] for _ in range(n)]

        cnt = 0
        q = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    cnt += 1
                    vis[i][j] = True
                    q.append([0, i, j])
        
        if cnt == 0 or cnt == n * m:
            return -1
        while q:
            t, r, c = q.popleft()
            time = max(time, t)
            for i in range(len(dirs)):
                nr = r + dirs[i][0]
                nc = c + dirs[i][1]
                if 0 <= nr < n and 0 <= nc < m and not vis[nr][nc]:
                    vis[nr][nc] = True
                    q.append([t + 1, nr, nc])
        
        return time