class Solution(object):
    def constructTransformedArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        r = []
        for i in range(n):
            j = (i + nums[i] + n) % n
            r.append(nums[j])
        return r