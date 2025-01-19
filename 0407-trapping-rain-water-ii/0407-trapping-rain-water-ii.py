class Solution(object):
    def trapRainWater(self, mat):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        n, m = len(mat), len(mat[0])
        minHeap = []
        vis = [[False for _ in range(m)] for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if i == 0 or j == 0 or i == n - 1 or j == m - 1:
                    heapq.heappush(minHeap, [mat[i][j], [i, j]])
                    vis[i][j] = True
        
        ans = 0
        while minHeap:
            temp = heapq.heappop(minHeap)
            val = temp[0]
            x = temp[1][0]
            y = temp[1][1]
            for i in range(len(dirs)):
                nx = x + dirs[i][0]
                ny = y + dirs[i][1]
                if nx >= 0 and ny >= 0 and nx < n and ny < m and not vis[nx][ny]:
                    vis[nx][ny] = True
                    ans += max(0, val - mat[nx][ny])
                    heapq.heappush(minHeap, [max(val, mat[nx][ny]), [nx, ny]])
        
        return ans