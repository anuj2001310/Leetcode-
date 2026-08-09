class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suffix = 0
        dp = [[0] * (n + 1) for _ in range(n)]

        for i in range(n - 1, -1, -1):
            suffix += piles[i]
            for m in range(1, i // 2 + 2):
                if i + m * 2 >= n:
                    dp[i][m] = suffix
                else:
                    dp[i][m] = suffix - min(dp[i + x][max(m, x)] for x in range(1, m * 2 + 1))
                    # mini = float('inf')
                    # for x in range(1, 2 * m + 1):
                    #     mini = min(mini, dp[i + x][max(m, x)])
                    #     dp[i][m] = suffix - mini
        return dp[0][1]

    