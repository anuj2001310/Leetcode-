class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        ans, l, r, curr = 0, 0, 0, 0
        m = max(nums)
        while r < n:
            curr += 1 if nums[r] == m else 0
            while curr >= k:
                curr -= 1 if nums[l] == m else 0
                l += 1
            ans += l
            r += 1
        return ans