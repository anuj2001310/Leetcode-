class Solution(object):
    def smallestIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        for i in range(n):
            s = sum(int(x) for x in str(nums[i]))
            if s == i:
                return i
        return -1