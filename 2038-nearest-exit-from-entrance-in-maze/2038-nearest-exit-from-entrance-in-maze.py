class Solution(object):
    def nearestExit(self, maze, entrance):
        """
        :type maze: List[List[str]]
        :type entrance: List[int]
        :rtype: int
        """
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        n, m = len(maze), len(maze[0])
        
        vis = [[False for _ in range(m)] for _ in range(n)]
        q = deque()

        u, v = entrance[0], entrance[1]
        vis[u][v] = True
        q.append([0, u, v])

        while q:
            [d, r, c] = q.popleft()
            temp = [r, c]
            if (r == 0 or c == 0 or r == n - 1 or c == m - 1) and temp != entrance:
                return d
            
            for di in dirs:
                nr = r + di[0]
                nc = c + di[1]
                if nr >= 0 and nr < n and nc >= 0 and nc < m and not vis[nr][nc] and maze[nr][nc] == '.':
                    q.append([d + 1, nr, nc])
                    vis[nr][nc] = True
        return -1