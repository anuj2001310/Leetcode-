class Solution:
    def minMergedInteger(self, nums: list[int]) -> int:
        ans = inf
        n = len(nums)
        for i in range(0, n - 1, 2):
            x, y = str(nums[i]), str(nums[i + 1])
            ans = min(ans, int(x + y))
        
        return ans