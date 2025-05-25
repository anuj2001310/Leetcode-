class Solution(object):
    def findClosestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        closest = nums[0]
        for i in range(len(nums)):
            if abs(nums[i]) < abs(closest):
                closest = nums[i]
            elif abs(nums[i]) == abs(closest) and nums[i] > closest:
                closest = nums[i]
            
        return closest