class Solution(object):
    def maximumBeauty(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        d = 2 * k
        l = 0
        for n in nums:
          if nums[l] + d < n:
            l += 1
        return len(nums) - l