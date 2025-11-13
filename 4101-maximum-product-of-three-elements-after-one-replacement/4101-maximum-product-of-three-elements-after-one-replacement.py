class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = 0
        ans = 10 ** 5
        first, second = -ans, -ans
        for i in range(n):
            if nums[i] != 0:
                cnt += 1

            if abs(nums[i]) >= first:
                second = first
                first = abs(nums[i])

            elif abs(nums[i]) > second and abs(nums[i]) != first:
                second = abs(nums[i])

        if cnt <= n // 3:
            return 0

        return abs(first * second * ans)
            
                