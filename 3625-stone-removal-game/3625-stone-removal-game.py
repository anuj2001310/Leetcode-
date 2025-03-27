class Solution(object):
    def canAliceWin(self, n):
        """
        :type n: int
        :rtype: bool
        """
        for i in range(10, -1, -1):
            if n < i:
                return i & 1 != 0
            n -= i
        return False