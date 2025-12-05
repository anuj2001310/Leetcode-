class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        n = len(nums)
        s = sum(nums)
        if s & 1:
            return 0

        l, cnt = 0, 0

        for i in range(n - 1):
            l += nums[i]
            rem = abs(s - 2 * l)

            if rem & 1 == 0:
                cnt += 1

        return cnt
