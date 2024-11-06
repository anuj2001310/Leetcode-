class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = 0
        n = len(nums)
        i, c = 0, 0
        while i < n:
            if nums[i] == 1:
                c += 1
            else:
                if c > m:
                    m = c
                c = 0
            i += 1
        m = max(m, c)
        return m