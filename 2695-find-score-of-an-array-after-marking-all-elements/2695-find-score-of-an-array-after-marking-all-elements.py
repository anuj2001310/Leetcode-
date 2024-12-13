class Solution(object):
    def findScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        res = sorted((nums[i], i) for i in range(n))
        ans = 0
        marked = [False] * n
        
        for val, ind in res:
            if not marked[ind]:
                ans += val
                marked[ind] = True
                if ind > 0:
                    marked[ind - 1] = True
                if ind < n - 1:
                    marked[ind + 1] = True
        
        return ans