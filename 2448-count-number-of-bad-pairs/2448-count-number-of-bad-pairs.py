class Solution(object):
    def countBadPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        tot = n * (n - 1) // 2
        freq = {}
        good = 0
        for i, num in enumerate(nums):
            diff = num - i
            if diff in freq:
                good += freq[diff]
                freq[diff] += 1
            else:
                freq[diff] = 1
        
        return tot - good