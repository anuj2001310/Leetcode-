class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt, r, s = 0, 0, 0
        h = {}
        h[s] = 1

        while r < n:
            s += nums[r]
            if s - k in h:
                cnt += h[s - k]
            h[s] = h.get(s, 0) + 1
            r += 1
        
        return cnt