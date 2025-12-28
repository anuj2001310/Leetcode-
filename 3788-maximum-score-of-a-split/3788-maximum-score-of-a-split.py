class Solution:
    def maximumScore(self, nums: List[int]) -> int:
        n = len(nums)
        prefix = [0] * n
        suffix = [inf] * n
        prefix[0] = nums[0]
        suffix[n - 1] = nums[n - 1]

        for i in range(1, n):
            prefix[i] = prefix[i - 1] + nums[i]

        #print(prefix)
        for i in range(n - 2, -1, -1):
            suffix[i] = min(suffix[i + 1], nums[i])
        
        #print(suffix)
        ans = -inf
        for i in range(n - 1):
            ans = max(ans, (prefix[i] - suffix[i + 1]))
        return ans