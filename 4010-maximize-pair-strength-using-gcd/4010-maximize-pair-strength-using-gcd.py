class Solution:
    def maxPairStrength(self, nums: list[int]) -> int:
        n = len(nums)
        l = r = 0
        ans = -inf

        while l < n:
            r = l + 1
            while r < n:
                res = (nums[l] * nums[r]) // ((math.gcd(nums[l], nums[r])) ** 2)
                ans = max(ans, res)
                r += 1
            l += 1
        
        return ans