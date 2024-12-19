class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        c, m = 0, -1
        for idx, ele in enumerate(arr):
            m = max(m, ele)
            if m == idx:
                c += 1
        
        return c