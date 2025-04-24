class Solution(object):
    def maximumPossibleSize(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = 1
        num = nums[0]
        for i in range(1, len(nums)):
            if nums[i] >= num:
                cnt += 1
                num = nums[i]
        return cnt