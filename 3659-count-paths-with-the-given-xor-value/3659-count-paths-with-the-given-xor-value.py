class Solution:
    def countPathsWithXorValue(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        @cache
        def helper(i, j, val):
            if i == 0 and j == 0:
                if val == grid[i][j]:
                    return 1
                return 0
            ans = 0
            if i > 0:
                ans += helper(i - 1, j, val ^ grid[i][j])

            if j > 0:
                ans += helper(i, j - 1, val ^ grid[i][j])

            return ans % 1000000007

        return helper(m - 1, n - 1, k)