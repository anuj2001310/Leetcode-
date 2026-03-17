class Solution:
    def smallestBalancedIndex(self, nums: list[int]) -> int:
        n = len(nums)
        s, pro = sum(nums), 1

        for i in range(n - 1, -1, -1):
            s -= nums[i]
            if s == pro:
                return i
            if pro > s // nums[i]:
                break
            
            pro *= nums[i]
        
        return -1