class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        l = 0
        h = nums[0]
        bit = False
        for i in range(1, len(nums)):
            bit = (bin(h).count('1') != bin(nums[i]).count('1'))
            if bit:
                l = h
            if nums[i] > h:
                h = nums[i]
            if nums[i] < l:
                return False
        
        return True