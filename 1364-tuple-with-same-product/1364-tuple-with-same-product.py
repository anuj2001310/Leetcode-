class Solution(object):
    def tupleSameProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        map = {}
        for i in range(n - 1):
            for j in range(i + 1, n):
                p = nums[i] * nums[j]
                map[p] = map.get(p, 0) + 1
        
        return sum(((w * (w - 1)) * 4) for w in map.values() if w > 1)
