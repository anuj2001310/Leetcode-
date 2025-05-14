class Solution(object):
    def canPartitionGrid(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        n, m = len(grid), len(grid[0])
        rowSum, colSum = [0 for _ in range(n)], [0 for _ in range(m)]
        tot = 0
        for i in range(n):
            for j in range(m):
                tot += grid[i][j]
                rowSum[i] += grid[i][j]
                colSum[j] += grid[i][j]

        if tot & 1:
            return False
            
        pref = 0   
        for i in range(n - 1):
            pref += rowSum[i]
            if (pref << 1) == tot:
                return True

        pref = 0
        for j in range(m - 1):
            pref += colSum[j]
            if (pref << 1) == tot:
                return True
            
        return False