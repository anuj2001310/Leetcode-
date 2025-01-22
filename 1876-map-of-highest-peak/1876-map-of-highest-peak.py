class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        n, m = len(isWater), len(isWater[0])
        res = [[-1 for _ in range(m)] for _ in range(n)]
        q = deque()
        for i in range(n):
            for j in range(m):
                if isWater[i][j] == 1:
                    q.append([i, j])
                    res[i][j] = 0
        
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        while q:
            [r, c] = q.popleft()
            for i in range(len(dirs)):
                nr = r + dirs[i][0]
                nc = c + dirs[i][1]
                if 0 <= nr < n and 0 <= nc < m and res[nr][nc] == -1:
                    res[nr][nc] = res[r][c] + 1
                    q.append([nr, nc])
        
        return res