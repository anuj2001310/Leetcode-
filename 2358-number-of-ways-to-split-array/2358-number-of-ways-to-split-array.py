class Solution(object):
    def waysToSplitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        rsum, lsum = sum(nums), 0
        cnt = 0

        for i in range(n - 1):
            lsum += nums[i]
            rsum -= nums[i]
            if lsum >= rsum:
                cnt += 1
            
        return cnt
        
