class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        n, m = len(coins), len(coins[0])
        f = [[[-inf] * 4 for _ in range(m)] for _ in range(n)]
        f[0][0][2] = coins[0][0]
        f[0][0][1] = 0
        for i in range(1, n):
            x = coins[i][0]
            for k in range(3):
                if x >= 0:
                    f[i][0][k] = f[i - 1][0][k] + x
                else:
                    f[i][0][k] = max(f[i - 1][0][k] + x, f[i - 1][0][k + 1])
        for j in range(1, m):
            x = coins[0][j]
            for k in range(3):
                if x >= 0:
                    f[0][j][k] = f[0][j - 1][k] + x
                else:
                    f[0][j][k] = max(f[0][j - 1][k] + x, f[0][j - 1][k + 1])

        for i in range(1,  n):
            for j in range(1, m):
                x = coins[i][j]
                for k in range(3):
                    if x >= 0:
                        f[i][j][k] = max(f[i - 1][j][k], f[i][j - 1][k]) + x
                    else:
                        f[i][j][k] = max(f[i - 1][j][k] + x, f[i][j - 1][k] + x, f[i - 1][j][k + 1], f[i][j - 1][k + 1])
        return max(f[-1][-1])