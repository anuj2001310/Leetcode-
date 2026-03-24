class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        ans = [[1 for _ in range(m)] for _ in range(n)]

        left, right = 1, 1
        MOD = 12345

        for i in range(n):
            for j in range(m):
                ans[i][j] = (ans[i][j] * left) % MOD
                left = (left * grid[i][j]) % MOD
        

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                ans[i][j] = (ans[i][j] * right) % MOD
                right = (right * grid[i][j]) % MOD

        return ans