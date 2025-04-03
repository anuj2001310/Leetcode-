class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        ans = dmax = imax = 0
        for i in range(n):
            ans = max(ans, dmax * nums[i])
            dmax = max(dmax, imax - nums[i])
            imax = max(imax, nums[i])
        
        return ans