class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        ans = abs(nums[0] - nums[n - 1])
        for i in range(1, n):
            val = abs(nums[i - 1] - nums[i])
            ans = max(ans, val)
        
        return ans