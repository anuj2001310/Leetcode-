class Solution(object):
    def maxAscendingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        t = nums[0]
        m = 0
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                t += nums[i]
            else:
                m = max(m, t)
                t = nums[i]
        return max(m, t)