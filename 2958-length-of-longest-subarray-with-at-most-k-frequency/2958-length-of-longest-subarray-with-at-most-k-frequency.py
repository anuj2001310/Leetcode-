class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        l = 0
        freq = {}
        ans = -inf

        for r in range(n):
            freq[nums[r]] = freq.get(nums[r], 0) + 1
            while freq[nums[r]] > k:
                freq[nums[l]] -= 1
                l += 1
            
            ans = max(ans, r - l + 1)

        return ans