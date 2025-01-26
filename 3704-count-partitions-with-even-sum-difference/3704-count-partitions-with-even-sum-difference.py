class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        s = sum(nums)
        left, cnt = 0, 0
        for i in range(len(nums) - 1):
            left += nums[i]
            if ((abs(s - 2 * left)) & 1) == 0:
                cnt += 1
        return cnt