class Solution(object):
    def consecutiveSetBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        cnt, p = 0, -1
        while n:
            r = n % 2
            if r == 1 and r == p:
                cnt += 1
            n >>= 1
            p = r
        
        return cnt == 1