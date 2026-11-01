class Solution:
    def minMergedInteger(self, nums: list[int]) -> int:
        ans = inf
        n = len(nums)
        for i in range(1, n, 2):
            x, y = str(nums[i - 1]), str(nums[i])
            ans = min(ans, int(x + y))
        
        return ans