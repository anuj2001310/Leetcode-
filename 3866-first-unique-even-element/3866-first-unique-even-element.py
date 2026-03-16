class Solution:
    def firstUniqueEven(self, nums: list[int]) -> int:
        n = len(nums)
        m = [0] * 101

        for num in nums:
            m[num] += 1
        
        for i in range(n):
            if (nums[i] & 1) == 0 and m[nums[i]] == 1:
                return nums[i]
            
        return -1