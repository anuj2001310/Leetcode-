class Solution(object):
    def centeredSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        ans = 0
        for i in range(n):
            s = set()
            sm = 0
            for j in range(i, n):
                sm += nums[j]
                s.add(nums[j])

                if sm in s:
                    ans += 1
        
        return ans