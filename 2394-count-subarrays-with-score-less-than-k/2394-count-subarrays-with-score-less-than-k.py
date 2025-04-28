class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
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