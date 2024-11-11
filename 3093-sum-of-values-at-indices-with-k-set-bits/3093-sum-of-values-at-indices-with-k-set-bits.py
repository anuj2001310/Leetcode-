class Solution(object):
    def sumIndicesWithKSetBits(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def bist(n):
            bit = 0
            while n:
                n &= (n - 1)
                bit += 1
            return bit

        sm = 0
        for i in range(len(nums)):
            if bist(i) == k:
                sm += nums[i]
        return sm