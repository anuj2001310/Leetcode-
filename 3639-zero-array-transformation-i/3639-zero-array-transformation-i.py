class Solution(object):
    def isZeroArray(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: bool
        """
        n = len(nums)
        res = [0] * (n + 1)
        for q in queries:
            l = q[0]
            r = q[1]
            res[l] += 1
            res[r + 1] -= 1
        
        for i in range(1, n + 1):
            res[i] += res[i - 1]
        
        for i in range(n):
            if res[i] < nums[i]:
                return False
        
        return True