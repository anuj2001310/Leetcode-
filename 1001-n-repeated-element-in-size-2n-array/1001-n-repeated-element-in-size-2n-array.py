class Solution(object):
    def repeatedNTimes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = []
        for num in nums:
            if num in res:
                return num
            else:
                res.append(num)