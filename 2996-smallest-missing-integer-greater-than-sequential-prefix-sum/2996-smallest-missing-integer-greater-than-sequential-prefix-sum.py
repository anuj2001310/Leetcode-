class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        n = len(nums)
        s = nums[0]
        for i in range(1, n):
            if nums[i - 1] + 1 == nums[i]:
                s += nums[i]
            else:
                break
        
        if s not in nums:
            return s
        
        while s in nums:
            s += 1
        
        return s