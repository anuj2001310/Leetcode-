class Solution(object):
    def specialTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10 ** 9 + 7
        n = len(nums)

        maximum = max(nums)
        maxsize = 2 * maximum + 1

        left = [0 for _ in range(maxsize)]
        right = [0 for _ in range(maxsize)]
        ans = 0

        for num in nums:
            right[num] += 1
        for j in range(n):
            right[nums[j]] -= 1
            val = 2 * nums[j]
            lval = left[val]
            rval = right[val]

            ans = (ans + (lval * rval)) % MOD

            left[nums[j]] += 1
        return ans