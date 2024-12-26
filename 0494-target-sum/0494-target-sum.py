class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = [[-1] * 2001 for _ in range(len(nums))]
        def dfs(idx, summ):
            if idx == len(nums):
                if summ == target:
                    return 1
                else:
                    return 0
            if dp[idx][summ + 1000] != -1:
                return dp[idx][summ + 1000]
            
            dp[idx][summ + 1000] = dfs(idx + 1, summ + nums[idx]) + dfs(idx + 1, summ - nums[idx])
            return dp[idx][summ + 1000]
        
        return dfs(0, 0)