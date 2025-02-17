class Solution:
    def check(self, nums: List[int]) -> bool:
        cnt, n = 0, len(nums)
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                cnt += 1
        
        if nums[n - 1] > nums[0]:
            cnt += 1
        
        return cnt <= 1