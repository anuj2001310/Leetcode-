class Solution(object):
    def isArraySpecial(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return all((nums[i] & 1) != (nums[i - 1] & 1) for i in range(1, len(nums)))