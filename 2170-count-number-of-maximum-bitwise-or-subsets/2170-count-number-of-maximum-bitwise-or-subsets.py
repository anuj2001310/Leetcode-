class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        dp = collections.Counter([0])
        for n in nums:
            for k, v in list(dp.items()):
                dp[k | n] += v
        return dp[max(dp)]