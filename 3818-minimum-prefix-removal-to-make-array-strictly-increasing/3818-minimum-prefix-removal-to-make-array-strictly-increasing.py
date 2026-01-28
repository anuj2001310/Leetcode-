class Solution(object):
    def minimumPrefixLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        for i in range(n - 1, 0, -1):
            if nums[i] <= nums[i - 1]:
                return i
        return 0