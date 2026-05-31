class Solution(object):
    def digitFrequencyScore(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = 0
        while n:
            s += n % 10
            n //= 10
        
        return s