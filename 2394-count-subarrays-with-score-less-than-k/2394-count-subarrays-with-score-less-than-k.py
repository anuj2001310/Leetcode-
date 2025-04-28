class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        res, cnt, sm = 0, 0, 0
        n, l = len(nums), 0
        for i in range (n):
            sm += nums[i]
            cnt += 1
            while sm * cnt >= k:
                cnt -= 1
                sm -= nums[l]
                l += 1
            res += cnt
        return res
