class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        vis = [0] * 101
        for num in nums:
            if num < k:
                return -1
            elif num > k:
                vis[num] += 1
        
        return sum(1 for v in vis if v != 0)