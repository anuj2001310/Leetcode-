class Solution:
    def minScoreTriangulation(self, nums: List[int]) -> int:
        N = len(nums)
        dp = [[0] * N for _ in range(N)]
        for start in reversed(range(N)):
            for end in range(start + 2, N):
                score = float(inf)
                for k in range(start + 1, end):
                    score = min(score, nums[start] * nums[k] * nums[end] + dp[start][k] + dp[k][end])
                dp[start][end] = score
        return dp[0][N - 1]