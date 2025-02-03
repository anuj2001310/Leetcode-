class Solution(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        inc = [1 for _ in range(n)]
        dec = [1 for _ in range(n)]
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                inc[i] = inc[i - 1] + 1
            if nums[i] < nums[i - 1]:
                dec[i] = dec[i - 1] + 1
        
        ans = 0
        for i in range(n):
            ans = max(ans, inc[i])
            ans = max(ans, dec[i])
        return ans