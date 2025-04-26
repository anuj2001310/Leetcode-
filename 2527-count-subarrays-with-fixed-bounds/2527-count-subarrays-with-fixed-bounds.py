class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        """
        :type nums: List[int]
        :type minK: int
        :type maxK: int
        :rtype: int
        """
        n, left_bnd, lst_min, lst_max = len(nums), -1, -1, -1
        cnt = 0
        for i in range(n):
            if nums[i] >= minK and nums[i] <= maxK:
                lst_min = i if nums[i] == minK else lst_min
                lst_max = i if nums[i] == maxK else lst_max

                cnt += max(0, min(lst_min, lst_max) - left_bnd)
            else:
                left_bnd = i
                lst_min = -1
                lst_max = -1
        return cnt