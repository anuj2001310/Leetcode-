class Solution(object):
    def smallestNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        while n & (n + 1) != 0:
            n |= (n >> 1)
        return n