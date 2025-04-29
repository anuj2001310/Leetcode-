class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        r, l, ans, curr = 0, 0, 0, 0
        m = max(nums)
        while r < n:
            curr += 1 if nums[r] == m else 0
            while curr >= k:
                curr -= 1 if nums[l] == m else 0
                l += 1
            ans += l
            r += 1
        return ans
