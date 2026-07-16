class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        curr = nums[0]

        for i in range(n):
            if nums[i] > curr:
                curr = nums[i]
            
            nums[i] = math.gcd(nums[i], curr)
        
        nums.sort()
        s = 0

        for i in range(n >> 1):
            s += math.gcd(nums[i], nums[~i])
        
        return s