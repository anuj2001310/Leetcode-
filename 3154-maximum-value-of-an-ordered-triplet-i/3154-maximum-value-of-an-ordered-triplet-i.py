class Solution(object):
    def maximumTripletValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        ans = dmax = imax = 0
        for i in range(n):
            ans = max(ans, dmax * nums[i])
            dmax = max(dmax, imax - nums[i])
            imax = max(imax, nums[i])
        
        return ans