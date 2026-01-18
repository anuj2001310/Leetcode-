class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        ans, n, m = 1, len(grid), len(grid[0])
        hprf = [list(accumulate(grid[i])) + [0] for i in range(n)]
        vprf = [list(accumulate(list(zip(*grid))[j])) + [0] for j in range(m)]
        d1, d2 = [[0] * (m + 1) for i in range(n + 1)], [
            [0] * (m + 1) for i in range(n + 1)
        ]
        for i in range(n):
            for j in range(m):
                d1[i][j] = grid[i][j] + d1[i - 1][j - 1]
                d2[i][j] = grid[i][j] + d2[i - 1][j + 1]
        for i in range(n - 1):
            for j in range(m - 1):
                for k in range(min(n - 1 - i, m - 1 - j), 0, -1):
                    k1, good = (
                        k,
                        (s := d1[i + k][j + k] - d1[i - 1][j - 1])
                        == d2[i + k][j] - d2[i - 1][j + k + 1],
                    )
                    while good and k1 >= 0:
                        good = (
                            s
                            == hprf[i + k1][j + k] - hprf[i + k1][j - 1]
                            == vprf[j + k1][i + k] - vprf[j + k1][i - 1]
                        )
                        k1 -= 1
                    if good:
                        ans = max(ans, k + 1)
                        break
        return ans
